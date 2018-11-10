// Simulated System Class
//
// Author: Matthew Knight
// File Name: sampled-system.cpp
// Date: 2018-11-10
//
// This class represents a real life system that is being simulated.

#include "simulated-system.hpp"

// period setter
void SimulatedSystem::setPeriod(double newPeriod) {
	period = newPeriod;
}

// period getter
double SimulatedSystem::getPeriod() {
	return period;
}
