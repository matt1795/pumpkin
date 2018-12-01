// Multiple Input Single Output System
//
// Author: Matthew Knight
// File Name: miso.hpp
// Date: 2018-11-25
//
// This interface is for systems that have multiple inputs with a single output

#pragma once

#include <tuple>

template <typename Output, typename ...Inputs>
class MISO {
public:
	// insert new inputs
	virtual void in(Inputs... inputs) = 0;

	// get output
	virtual Output out() = 0;
};
