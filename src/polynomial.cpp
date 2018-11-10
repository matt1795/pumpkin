// Polynomial System
//
// Author: Matthew Knight
// File Name: polynomial.hpp
// Date: 2018-11-09
//
// This class implements a simple polynomial equation.

#pragma once

#include "siso.hpp"

#include <vector>

// ctor
Polynomial::Polynomial(const std::vector<double>& weights) : weights(weights) 
{}

// input new value
void Polynomial::in(const double& val) {
	double x = 1;
	y = 0;
	
	for (auto w : weights) {
		y += w*x;
		x *= val;
	}
}

// get output value
double Polynomial::out() {
	return y;
}
