//
// pch.cpp
//

#include "pch.h"

//std::mt19937 generator{ 42 };
std::mt19937 generator{ std::random_device{}() };

int getInt(int min, int max) {
	auto dist = std::uniform_int_distribution<int>(min, max);
	return dist(generator);
}
std::ostream& operator << (std::ostream& stream, const Arb& a)
{
	return stream << "Arb(" << a._val << ")";
};