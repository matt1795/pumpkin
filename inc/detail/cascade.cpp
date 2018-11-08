// Cascade System Class
//
// Author: Matthew Knight
// File Name: cascade.cpp
// Date: 2018-11-06
//
// This class chains classes in a serial fashion using multiple mechanisms as an
// interface. Currently it can only chain systems that have the same input and
// output type currently

#include "cascade.hpp"

#include <vector>

#include <cstdarg>

// vector ctor
template <class T>
Cascade<T>::Cascade(std::vector<SISO<T, T>::Ptr> systems) : systems(systems) {}

// add new input value
template <class T>
void Cascade<T>::in(T const &val) {
	systems.front()->in(val);
	for (int i = 1; i < systems.size(); i++)
		systems[i]->in(systems[i-1]->out());
}

// get last output value
template <class T>
T Cascade<T>::out() {
	return systems.back()->out();
}
