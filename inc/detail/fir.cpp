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
FIR<T>::FIR(std::vector<T> const &weights, T denominator) 
	: y(0)
	, h(weights)
	, x(2*h.size(), 0)
	, den(denominator)
{}

// calculate next output value
template <typename T>
T FIR<T>::calculate() {
	T val = 0;
	for (int i = 0; i < h.size(); i++)
		val += x[i + offset]*h[i];
	
	return val / den;
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
	y = calculate();
}

// get last output value
template <typename T>
T FIR<T>::out() {
	return y;
}
