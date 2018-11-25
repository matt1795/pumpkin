// Integral "System"
//
// Author: Matthew Knight
// File Name: integral.hpp
// Date: 2018-11-25
//
// This class implements an integral operation, it is mostly intended for system
// composing. Instead of using a rectangular based integrating method, this one
// uses a triangle method to better approximate the input signal.

#pragma once

#include "siso.hpp"

#include <array>

template <typename T, size_t Order>
class Integral : public SISO<T> {
	std::array<std::array<T, 2>, Order + 1> arr = {{ 0 }};
	double period = 0.001;

public:
	// ctors
	Integral() = default;
	Integral(double period);

	// input new value
	void in(T val);

	// return output
	T out();

	// access specific integration
	T& operator[](size_t index);
};

#include "detail/integral.cpp"
