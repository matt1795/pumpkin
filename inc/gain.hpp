// Gain "System"
//
// Author: Matthew Knight
// File name: gain.hpp
// Date: 2018-11-25
//
// This is a simple class used as a helper for composition of more complicated
// systems.

#pragma once

#include "siso.hpp"

template <typename T>
class Gain {
	T output = 0;;
	T gain = 1;

public:
	// ctors
	Gain() = default;
	Gain(T gain) : gain(gain) {}

	// input
	void in(T val) {
		output = gain * val;
	}

	// output
	T out() {
		return output;
	}
};
