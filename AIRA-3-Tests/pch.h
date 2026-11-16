//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <random>
#include <iostream>

int getInt(int min, int max);


class Arb {
public:
	int _val;
	Arb() : _val(0) {};
	Arb(int val) : _val(val) {};
};
std::ostream& operator << (std::ostream& stream, const Arb& a);