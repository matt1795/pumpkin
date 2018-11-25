// Simulated Second Order System
//
// Author: Matthew Knight
// File Name: second-order
// Date: 2018-11-18
//
// This class implements a simulated second order system.

#pragma once

#include "integral.hpp"
#include "simulated-system.hpp"

#include <array>

class SecondOrder : public SimulatedSystem {
	// system characteristics
	double gain = 1;
	double zeta = 1;
	double omega = 1;

	Integral<double, 2> x, y;

public:
	// ctors
	SecondOrder() = default;
	SecondOrder(double zeta, double omega);
	SecondOrder(double zeta, double omega, double gain);
	SecondOrder(double zeta, double omega, double gain, double period);

	// insert new input
	void in(double val) override;

	// get new output
	double out() override;
};
