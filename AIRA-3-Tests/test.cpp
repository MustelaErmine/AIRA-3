#include "pch.h"
#include "../AIRA-3/insertionsort.hpp"
#include "../AIRA-3/quicksort.hpp"

TEST(Insertion, Int) {
#define LENGTH 100

	// Arrange
	int a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = getInt(0, LENGTH);
	}

	auto comp = [](int a, int b) { return a < b; };
	auto comp_ensure = [](int a, int b) { return a <= b; };
	
	// Act
	insertionsort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp_ensure));

#undef LENGTH
}
TEST(Insertion, Arbitary) {
#define LENGTH 100
	// Arrange
	Arb a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = Arb(getInt(0, LENGTH));
	}

	auto comp = [](Arb a, Arb b) { return a._val < b._val; };
	auto comp_ensure = [](Arb a, Arb b) { return a._val <= b._val; };
	
	// Act
	insertionsort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp_ensure));

#undef LENGTH
}

TEST(Quick, Int) {
#define LENGTH 100

	// Arrange
	int a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = getInt(0, LENGTH);
	}

	auto comp = [](int a, int b) { return a < b; };
	auto comp_ensure = [](int a, int b) { return a <= b; };

	// Act
	quicksort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp_ensure));

#undef LENGTH
}

TEST(Quick, Arb) {
#define LENGTH 100
	// Arrange
	Arb a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = Arb(getInt(0, LENGTH));
	}

	auto comp = [](Arb a, Arb b) { return a._val < b._val; };
	auto comp_ensure = [](Arb a, Arb b) { return a._val <= b._val; };

	// Act
	quicksort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp_ensure));

#undef LENGTH
}

TEST(Partition, Int) {
#define LENGTH 10

	// Arrange
	int a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = getInt(0, LENGTH);
	}

	auto comp = [](int a, int b) { return a < b; };
	auto comp_ensure = [](int a, int b) { return a <= b; };

	// Act
	_partition(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);
	// Assert

#undef LENGTH
}