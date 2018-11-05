// Finite Impulse Response Filter
//
// Author: Matthew Knight
// File Name: fir.hpp
// Date: 2018-11-04
//
// This class implements a FIR Filter using the SISO class as a base.

#pragma once

#include "siso.hpp"

#include <vector>

template <typename T>
class FIR : public SISO<T> {
	std::vector<T> x;					// input values
	std::vector<T> h;					// weights (also impulse response)
	T y;								// holds last output value
	T den;								// used for integer values
	int offset;							// current offset

	// calculate current output
	T calculate();

public:
	// ctor
	FIR(std::vector<T> const &weights, T denominator=1);

	// add new input value
	void in(T const &val) override;

	// get last output value
	T out() override;
};

#include "detail/fir.cpp"
