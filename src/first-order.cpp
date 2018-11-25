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
void FirstOrder::in(double val) {
	x[1] = x[0];
	x[0] = val;
	y[1] = y[0];
	y[0] = ((gain * integrate(x, xAcc)) - integrate(y, yAcc)) / tau;
}

// get last output val
double FirstOrder::out() {
	return y[0];
}

double FirstOrder::integrate(const std::array<double, 2>& arr, double& acc) {
	acc += (period / 2) * (arr[0] + arr[1]);
	return acc;
}
