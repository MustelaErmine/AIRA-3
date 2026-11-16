#pragma once

#include "pch.h"
#include "insertionsort.hpp"

void b() {
	int a[100];

	insertionSort(a, a + 100, [](int a, int b) { return a < b; });
}