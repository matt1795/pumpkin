// First Order System
//
// Author: Matthew Knight
// File Name: first-order.hpp
// Date: 2018-11-17
//
// This class simulates a simple first order system

#pragma once

#include "integral.hpp"
#include "simulated-system.hpp"

#include <array>

class FirstOrder : public SimulatedSystem {
	double gain = 1;
	double tau = 1;

	// Integral accumulators
	Integral<double, 1> x, y;

public:
	// ctors
	FirstOrder() = default;
	FirstOrder(double tau);
	FirstOrder(double tau, double gain);
	FirstOrder(double tau, double gain, double period);

	// add new input value
	void in(double val) override;

	// get last output val
	double out() override;
};
