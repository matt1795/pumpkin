// Cascade System Class
//
// Author: Matthew Knight
// File Name: cascade.hpp
// Date: 2018-11-06
//
// This class chains classes in a serial fashion using multiple mechanisms as an
// interface. Currently it can only chain systems that have the same input and
// output type currently

#pragma once

#include <vector>

#include <cstdarg>

template <class T>
class Cascade : public SISO<T, T> {
	// cascaded systems
	std::vector<SISO<T, T> *> systems;

public:
	// vector ctor
	Cascade(std::vector<SISO<T, T> *> systems);

	// add new input value
	void in(T const &val) override;

	// get last output value
	T out() override;	
};
