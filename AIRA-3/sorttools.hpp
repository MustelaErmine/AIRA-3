#pragma once

#include "pch.h"

template <typename T>
int linear_length(T* first, T* last) {
	return last - first;
}

template <typename T>
T&& movecopy(T& value)
	requires (!std::is_trivial_v<T>&& std::is_move_constructible_v<T>)
{
	return std::move(value);
}
template <typename T>
const T& movecopy(T& value)
	requires (std::is_trivial_v<T> ||
(!std::is_move_constructible_v<T> && std::is_copy_constructible_v<T>))
{
	return value;
}

template <typename T>
void sortswap(T* left, T* right) {
	T tmp = movecopy(*left);
	*left = movecopy(*right);
	*right = movecopy(tmp);
}

template <typename T>
void printarray(T* first, T* last) {
	T* curPtr = first;
	while (curPtr != last) {
		std::cout << *curPtr << " ";
		curPtr++;
	}
	std::cout << *last << std::endl;
}