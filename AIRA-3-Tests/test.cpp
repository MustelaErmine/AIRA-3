#include "pch.h"
#include "../AIRA-3/insertionsort.hpp"
#include "../AIRA-3/quicksort.hpp"

#include <chrono>

TEST(Insertion, Int) {
#define LENGTH 100

	// Arrange
	int a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = getInt(0, LENGTH);
	}

	auto comp = [](int a, int b) { return a < b; };
	
	// Act
	insertionsort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

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
	
	// Act
	insertionsort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

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

	// Act
	quicksort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);
	string_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

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

	// Act
	quicksort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

#undef LENGTH
}

TEST(Quick, Inverse) {
#define LENGTH 100

	// Arrange
	int a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = LENGTH - i;
	}

	auto comp = [](int a, int b) { return a < b; };

	// Act
	quicksort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);
	string_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

#undef LENGTH
}

TEST(Quick, Forward) {
#define LENGTH 100

	// Arrange
	int a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = i;
	}

	auto comp = [](int a, int b) { return a < b; };

	// Act
	quicksort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);
	string_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

#undef LENGTH
}

TEST(Quick, Equal) {
#define LENGTH 100

	// Arrange
	int a[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		a[i] = 0;
	}

	auto comp = [](int a, int b) { return a < b; };

	// Act
	quicksort(a, a + LENGTH, comp);
	print_array(a, a + LENGTH);
	string_array(a, a + LENGTH);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

#undef LENGTH
}

TEST(Quick, Hugea) {
#define LENGTH 10000000

	// Arrange
	int* a = (int*)malloc(LENGTH * sizeof(int));

	for (int i = 0; i < LENGTH; i++) {
		a[i] = getInt(0, LENGTH);
	}

	auto comp = [](int a, int b) { return a < b; };

	// Act
	quicksort(a, a + LENGTH, comp);

	// Assert
	EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

	free(a);

#undef LENGTH
}

TEST(Quick, HugeTimer) {
#define LENGTH 1000000


	int* a = (int*)malloc(LENGTH * sizeof(int));
	// Arrange
	for (int i = 0; i < 100; i++) {
		LENGTH_FOR_INSERTION = i;

		for (int i = 0; i < LENGTH; i++) {
			a[i] = getInt(0, LENGTH);
		}

		auto comp = [](int a, int b) { return a < b; };


		auto start = std::chrono::steady_clock::now();
		// Act
		quicksort(a, a + LENGTH, comp);
		auto end = std::chrono::steady_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		std::cout <<  duration.count() << std::endl;

		// Assert
		EXPECT_TRUE(ensure_sorted(a, a + LENGTH, comp));

	}
	free(a);

#undef LENGTH
}