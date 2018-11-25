// Single Input / Single Output System Class
//
// Author: Matthew Knight
// File Name: siso.cpp
// Date: 2018-11-04
//
// This is an abstract class for all the different system types. It is templated
// so that different systems may be realized for high precision simulation vs.
// efficient embedded systems.
//
// The main idea right now is that when a new value is input, all the internal
// calculation values are run, and the output method just gets the latest
// calculated value.
//
// Later on we can play with the use of streams to provide input and output
// channels to a system.

#include "siso.hpp"

#include <iostream>

// set output stream
template <class Input, class Output>
void SISO<Input, Output>::stream(std::istream &is, std::ostream &os) {
	while (!is.eof()) {
		// extract next input
		Input x;
		is >> x;

		// run through system
		in(x);
		os << out() << std::endl;
	}
}
