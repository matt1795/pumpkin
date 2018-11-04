// Single Input / Single Output System Class
//
// Author: Matthew Knight
// File Name: siso.hpp
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

#pragma once

template <typename T>
class SISO {
public:
	// add new input value
	virtual void in(T const &val) = 0;

	// get last output value
	virtual T out() = 0;
};
