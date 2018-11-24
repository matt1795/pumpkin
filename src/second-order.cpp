// Simulated Second Order System
//
// Author: Matthew Knight
// File Name: second-order
// Date: 2018-11-18
//
// This class implements a simulated second order system.

#include "second-order.hpp"

// ctors
SecondOrder::SecondOrder(double zeta, double omega)
	: zeta(zeta)
	, omega(omega)
{}

SecondOrder::SecondOrder(double zeta, double omega, double gain)
	: zeta(zeta)
	, omega(omega)
	, gain(gain)
{}

SecondOrder::SecondOrder(double zeta, double omega, double gain, double period)
	: zeta(zeta)
	, omega(omega)
	, gain(gain)
	, SimulatedSystem(period)
{}

// insert new input
void SecondOrder::in(const double& val) {
	// shift buffer
	y[2] = y[1];
	y[1] = y[0];

	// calculate new output
	double a = omega * omega;
	double b = 2 * zeta * omega;

	double c = (a * (period * period)) + (b * period) + 1;

	double j = gain * a * period * period / c;
	double k = ((b * period) - 2) / c;
	double l = 1 / c;

	y[0] = (j * val) - (k * y[1]) - (l * y[2]);
}

// get new output
double SecondOrder::out() {
	return y[0];
}
