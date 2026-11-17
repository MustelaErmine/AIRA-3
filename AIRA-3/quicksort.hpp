#pragma once

#include "pch.h"
#include "insertionsort.hpp"
#include "sorttools.hpp"

#define _QS_LENGTH_FOR_INSERTION 7
#define _QS_LENGTH_FOR_RECURSION 42

SORT_FUNCTION
void quicksort(T* first, T* last, Compare comp) {
	auto length = linear_length(first, last);
	if (length <= 1) {
		return;
	}
	if (length <= _QS_LENGTH_FOR_INSERTION) {
		insertionsort(first, last, comp);
		return;
	}

	std::deque<std::pair<T*, T*>> sort_areas;
	sort_areas.push_back(std::make_pair(first, last));

	while (!sort_areas.empty()) {
		std::pair<T*, T*> area = sort_areas.front();
		sort_areas.pop_front();

		auto area_length = linear_length(area.first, area.second);
		if (area_length <= 1) {
			continue;
		}
		if (area_length <= _QS_LENGTH_FOR_INSERTION) {
			insertionsort(area.first, area.second, comp);
			continue;
		}
		T* support_place = _partition(area.first, area.second, comp);
		if (area_length <= _QS_LENGTH_FOR_RECURSION) {
			quicksort(area.first, support_place + 1, comp);
			quicksort(support_place + 1, area.second, comp);
			if (!ensure_sorted(area.first, area.second, comp)) {
				print_array(area.first, area.second);
			}
			continue;
		}
		sort_areas.push_back(std::make_pair(area.first, support_place + 1));
		sort_areas.push_back(std::make_pair(support_place + 1, area.second));
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