// Controller Interface
//
// Author: Matthew Knight
// File Name: controller.hpp
// Date: 2018-11-25
//
// This interface is for controllers within systems. Currently it is designed to
// have two inputs (reference and sensor signals) and an output. Later on we may
// add to this interface (measured disturbances for feed forward control?) but
// for now this is what we'll do.

#pragma once

#include "miso.hpp"

class Controller : public MISO<double, double, double> {
	void in(double reference, double sensor) = 0;

	double out() = 0;
};
