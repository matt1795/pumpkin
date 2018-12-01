// Proportional Controller
//
// Author: Matthew Knight
// File Name: proportional-control.hpp
// Date: 2018-11-25
//
// This is a simple P controller, it outputs a control signal in proportion to
// the error signal.

#pragma once

#include "controller.hpp"
#include "gain.hpp"

#include <tuple>

class ProportionalController : public Controller {
	Gain<double> sys;

public:
	ProportionalController() = default;
	ProportionalController(double gain) : sys(gain) {}

	void in(double reference, double sensor) {
		sys.in(sensor - reference);
	}

	double out() {
		return sys.out();
	}
};
