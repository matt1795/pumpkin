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
template <typename T>
FIR<T>::FIR(std::vector<T> const &weights) 
	: out(0), h(weights), x(2*h.size(), 0) {}

// calculate next output value
template <typename T>
T FIR<T>::calculate() {
	T val = 0;
	for (int i = 0; i < h.size(); i++)
		val += x[i + offset]*h[i];
	
	return val;
}

// add new input value
template <typename T>
void FIR<T>::in(T const &val) {
	// increment offset and check if is in bounds
	if (++offset >= h.size())
		offset = 0;

	// add value to buffer
	x[offset] = val;
	x[offset + h.size()] = val;

	// calculate new ouput
	out = calculate();
}

// get last output value
template <typename T>
T FIR<T>::out() {
	return out;
}
