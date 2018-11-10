// Parallelize Systems
//
// Author: Matthew Knight
// File Name: parallel.hpp
// Date: 2018-11-07
//
// This class encapsulates multiple SISO systems, pipes its inputs to all the
// enclosed systems and sums the outputs. The input type and output types must
// match for all enclosed systems.

#pragma once

#include "siso.hpp"

#include <vector>

template <class T>
class Parallel : public SISO<T> {
	std::vector<typename SISO<T>::Ptr> systems;

public:
	// ctor
	Parallel(const std::vector<typename SISO<T>::Ptr>& systems);

	// input new value
	void in(const T& in) override;

	// get output value
	T out() override;
};

#include "detail/parallel.cpp"
