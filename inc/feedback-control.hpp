// Feedback Control System
//
// Author: Matthew Knight
// File Name: feedback-control.hpp
// Date: 2018-11-25
//
// This is another composition type class which specifically arranges subsystems
// to create a feeback control architecture. Note that while most diagrams have
// the controller operate on an error signal, our controller will take in both
// the reference and measured signals for non-linear controllers down the road
// -- linear controllers will be able to calculate error on their own.

#pragma once

#include "controller.hpp"
#include "simulated-system.hpp"
#include "first-order.hpp"
#include "siso.hpp"

#include <memory>

class FeedbackControl : public SISO<double> {
	std::unique_ptr<Controller> controller;
	std::unique_ptr<SimulatedSystem> system, actuator, sensor;

public:
	FeedbackControl(
		Controller&& con,
		SimulatedSystem&& sys,
		SimulatedSystem&& act,
		SimulatedSystem&& sen
	) {
		*system = std::move(sys);
		*actuator = std::move(act);
		*sensor = std::move(sen);
	}

	void in(double val) {

	}

	double out() {
		return 1;
	}
};
