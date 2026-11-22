#pragma once

#include "pch.h"
#include "insertionsort.hpp"
#include "sorttools.hpp"

int LENGTH_FOR_INSERTION = 17;

SORT_FUNCTION
void quicksort(T* first, T* last, Compare comp) {
	auto length = linear_length(first, last);
	if (length <= 1) {
		return;
	}
	if (length <= LENGTH_FOR_INSERTION) {
		insertionsort(first, last, comp);
		return;
	}

	T* sort_start = first;
	T* sort_end = last;

	while (sort_start != nullptr && sort_end != nullptr) {
		auto area_length = linear_length(sort_start, sort_end);
		if (area_length <= 1) {
			break;
		}
		if (area_length <= LENGTH_FOR_INSERTION) {
			insertionsort(sort_start, sort_end, comp);
			break;
		}
		T* support_place = _partition(sort_start, sort_end, comp);

		auto length1 = linear_length(sort_start, support_place + 1);
		auto length2 = linear_length(support_place + 1, sort_end);

		if (length1 < length2) {
			quicksort(sort_start, support_place + 1, comp);
			sort_start = support_place + 1;
			//sort_end = sort_end;
		}
		else {
			quicksort(support_place + 1, sort_end, comp);
			//sort_start = sort_start;
			sort_end = support_place + 1;
		}
	}
	if (!ensure_sorted(first, last, comp)) {
		print_array(first, last);
	}
}

SORT_FUNCTION
T* _partition(T* first, T* last, Compare comp) {
	auto support = *_support_element(first, last, comp);
	T* left = first;
	T* right = last - 1;

	while (true) {
		while (left <= right && comp(*left, support)) {
			left++;
		}
		while (left <= right && comp(support, *right)) {
			right--;
		}
		if (left > right)
			break;

		if (left < right) {
			sortswap(left, right);
		}
		
		right--;
		left++;
	}
	return right;
}

SORT_FUNCTION
T* _support_element(T* first, T* last, Compare comp) {
	auto length = linear_length(first, last);
	auto rlast = last - 1;

	auto middle = first + length / 2;

	if (comp(*first, *middle) && comp(*middle, *rlast) || comp(*rlast, *middle) && comp(*middle, *first)) {
		return middle;
	}
	if (comp(*middle, *first) && comp(*first, *rlast) || comp(*rlast, *first) && comp(*first, *middle)) {
		return first;
	}
	return rlast;
}