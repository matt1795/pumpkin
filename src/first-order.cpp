// First Order System
//
// Author: Matthew Knight
// File Name: first-order.hpp
// Date: 2018-11-17
//
// This class simulates a simple first order system

#include "first-order.hpp"

class FirstOrder : public SimulatedSystem {
	double gain = 1;
	double tau = 1;

	// buffers
	double y[2] = { 0, 0 };

	FirstOrder(double tau) : tau(tau) {}
	FirstOrder(double tau, double gain) : tau(tau), gain(gain) {}
	FirstOrder(double tau, double gain, double period) : tau(tau), gain(gain), period(period) {}

	// add new input value
	void in(const double& val) {
		y[1] = y[0];
		double tmp = tau / period;
		y[0] = ((gain * val) + tmp) / (1 + tmp);
	}

	// get last output val
	double out() {
		return y[0];
	}
};
