// Finite Impulse Response Filter
//
// Author: Matthew Knight
// File Name: fir.cpp
// Date: 2018-11-04
//
// This class implements a FIR Filter using the SISO class as a base.

#include "fir.hpp"

#include <vector>

// ctor
template <class Input, class Output, class Acc>
FIR<Input, Output, Acc>::FIR(const std::vector<Input> &weights) 
	: h(weights)
	, x(2*weights.size(), 0)
	, y(0) 
{}

// calculate next output value
template <class Input, class Output, class Acc>
Output FIR<Input, Output, Acc>::calculate() {
	Acc val = 0;
	for (int i = 0; i < h.size(); i++)
		val += x[i + offset]*h[i];
	
	return val;
}

// add new input value
template <class Input, class Output, class Acc>
void FIR<Input, Output, Acc>::in(const Input &val) {
	// increment offset and check if is in bounds
	if (offset == 0)
		offset = h.size() - 1;
	else
		offset--;

	// add value to buffer
	x[offset] = val;
	x[offset + h.size()] = val;

	// calculate new ouput
	y = calculate();
}

// get last output value
template <class Input, class Output, class Acc>
Output FIR<Input, Output, Acc>::out() {
	return y;
}
