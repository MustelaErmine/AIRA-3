#pragma once

#include "pch.h"
#include "Comparator.h"

#define SORT_FUNCTION template <typename T, typename Compare> requires Comparator<Compare, T>

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
void print_array(T* first, T* last) {
	T* curPtr = first;
	while (curPtr != last) {
		std::cout << *curPtr << " ";
		curPtr++;
	}
	std::cout << std::endl;
}

template <typename T>
std::string string_array(const T* first, const T* last) {
	std::ostringstream stringBuilder;
	const T* curPtr = first;
	while (curPtr != last) {
		stringBuilder << *curPtr << " ";
		curPtr++;
	}
	stringBuilder << std::endl;
	return stringBuilder.str();
}

SORT_FUNCTION
bool ensure_sorted(T* first, T* last, Compare comp) {
	auto ptr = first;
	while (ptr + 2 != last) {
		if (comp(ptr[1], ptr[0]))
			return false;
		++ptr;
	}
	
	return true;
}