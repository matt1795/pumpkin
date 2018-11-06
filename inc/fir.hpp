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

template <class Input, class Output=Input, class Acc=Output>
class FIR : public SISO<Input, Output> {
	std::vector<Input> x;				// input values
	std::vector<Input> h;				// weights (also impulse response)
	Output y;							// holds last output value
	unsigned int offset;				// current offset

	// calculate current output
	Output calculate();

public:
	// ctor
	FIR(const std::vector<Input> &weights);

	// add new input value
	void in(const Input &val) override;

	// get last output value
	Output out() override;
};

#include "detail/fir.cpp"
