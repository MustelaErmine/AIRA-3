#include "pch.h"
#include "../AIRA-3/insertionsort.hpp"

TEST(Insertion, Int1) {
	// Arrange
	int a[100];
	for (int i = 0; i < 100; i++) {
		a[i] = getInt(0, 100);
	}
	
	// Act
	insertionSort(a, a + 100, [](int a, int b) { return a < b; });
}