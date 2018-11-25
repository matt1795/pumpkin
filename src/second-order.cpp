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
	, x(period)
	, y(period)
{}

// insert new input
void SecondOrder::in(double val) {
	double omegaSquared = omega * omega;
	x.in(val);
	y.in(
		(gain * omegaSquared * x[2])
		- (2 * zeta * omega * y[1])
		- (omegaSquared * y[2])
	);
}

// get new output
double SecondOrder::out() {
	return y[0];
}
