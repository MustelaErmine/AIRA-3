#pragma once

#include "pch.h"
#include "insertionsort.hpp"
#include "sorttools.hpp"

#define _QS_LENGTH_FOR_INSERTION 7
#define _QS_LENGTH_FOR_RECURSION 42

SORT_FUNCTION
void quicksort(T* first, T* last, Compare comp) {
	auto length = linear_length(first, last);
	if (length <= 1)
		return;

	if (length <= _QS_LENGTH_FOR_INSERTION) {
		insertionsort(first, last, comp);
		return;
	}

	(T*, T*) a[];
}

SORT_FUNCTION
T* _partition(T* first, T* last, Compare comp) {
	auto support = *_support_element(first, last, comp);
	T* left = first;
	T* right = last - 1;

	while (left != right) {
		while (comp(*left, support) && left != right) {
			left++;
		}
		while (comp(support, *right) && left != right) {
			right--;
		}
		if (left == right)
			break;

		sortswap(left, right);
		
		left++;
		if (left == right)
			break;
		right--;
	}
	return left;
}

SORT_FUNCTION
T* _support_element(T* first, T* last, Compare comp) {
	auto length = linear_length(first, last);

	auto middle = first + length / 2;

	if (comp(*first, *middle) && comp(*middle, *last) || comp(*last, *middle) && comp(*middle, *first)) {
		return middle;
	}
	if (comp(*middle, *first) && comp(*first, *last) || comp(*last, *first) && comp(*first, *middle)) {
		return middle;
	}
	return last;
}