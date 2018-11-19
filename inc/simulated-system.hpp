// Simulated System Class
//
// Author: Matthew Knight
// File Name: sampled-system.hpp
// Date: 2018-11-10
//
// This class represents a real life system that is being simulated.

#pragma once

#include "siso.hpp"

class SimulatedSystem : public SISO<double> {
protected:
	double period = 0.001; // milliseconds

public:
	// ctors
	SimulatedSystem() = default;
	SimulatedSystem(double period);

	// period setter
	virtual void setPeriod(double newPeriod);

	// period getter
	double getPeriod();
};

