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

#include <iostream>
#include <memory>

template <class Input, class Output=Input>
class SISO {
public:
	using Ptr = std::shared_ptr<SISO<Input, Output>>;

	// add new input value
	virtual void in(const Input& val) = 0;

	// get last output value
	virtual Output out() = 0;

	// filter from an input stream to an output stream 
	void stream(std::istream &is, std::ostream &os);
};

#include "detail/siso.cpp"
