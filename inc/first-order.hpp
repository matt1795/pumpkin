// First Order System
//
// Author: Matthew Knight
// File Name: first-order.hpp
// Date: 2018-11-17
//
// This class simulates a simple first order system

#pragma once

#include "simulated-system.hpp"

#include <array>
class FirstOrder : public SimulatedSystem {
	double gain = 1;
	double tau = 1;

	// Integral accumulators
	double xAcc = 0;
	double yAcc = 0;

	// buffers
	std::array<double, 2> y = {{ 0, 0 }};
	std::array<double, 2> x = {{ 0, 0 }};

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

private:
	double integrate(const std::array<double, 2>& arr, double& acc);
};
