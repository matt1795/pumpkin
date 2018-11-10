// Parallelize Systems
//
// Author: Matthew Knight
// File Name: parallel.cpp
// Date: 2018-11-07
//
// This class encapsulates multiple SISO systems, pipes its inputs to all the
// enclosed systems and sums the outputs. The input type and output types must
// match for all enclosed systems.

#include "parallel.hpp"

// ctor
template <class T>
Parallel<T>::Parallel(const std::vector<SISO<T>*>& systems)
	: systems(systems) {}

// input new value
template <class T>
void Parallel<T>::in(const T& val) {
	for (auto system : systems)
		system->in(val);
}

// get output value
template <class T>
T Parallel<T>::out() {
	T val = 0;
	for (auto system : systems)
		val += system->out();

	return val;
}
