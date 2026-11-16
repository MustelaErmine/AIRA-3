#pragma once

#include "pch.h"
#include "Comparator.h"
#include "sorttools.hpp"

SORT_FUNCTION
void insertionsort(T* first, T* last, Compare comp) {
	auto length = linear_length(first, last);

	for (int i = 1; i < length; i++) {
		int j = i - 1;
		while (j >= 0 && !comp(first[j], first[j + 1])) {
			sortswap(first + j, first + j + 1);
			--j;
		}
	}
}