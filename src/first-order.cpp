// First Order System
//
// Author: Matthew Knight
// File Name: first-order.hpp
// Date: 2018-11-17
//
// This class simulates a simple first order system

#include "first-order.hpp"

// ctors
FirstOrder::FirstOrder(double tau) : tau(tau) {}

FirstOrder::FirstOrder(double tau, double gain) : tau(tau), gain(gain) {}

FirstOrder::FirstOrder(double tau, double gain, double period)
	: tau(tau)
	, gain(gain)
	, SimulatedSystem(period)
{}

// add new input value
void FirstOrder::in(const double& val) {
	y[1] = y[0];
	double tmp = tau / period;
	y[0] = ((gain * val) + tmp) / (1 + tmp);
}

// get last output val
double FirstOrder::out() {
	return y[0];
}
