// Polynomial System
//
// Author: Matthew Knight
// File Name: polynomial.hpp
// Date: 2018-11-09
//
// This class implements a simple polynomial equation.

#pragma once

#include "siso.hpp"
#include "simulated-system.hpp"

#include <vector>

class Polynomial : public SimulatedSystem {
	std::vector<double> weights;
	double y = 0;

public:
	// ctor
	Polynomial(const std::vector<double>& weights);

	// input new value
	void in(const double& val) override;

	// get output value
	double out() override;
};
