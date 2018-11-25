// First Order System Simulation
//
// Author: Matthew Knight
// File Name: first-order.cpp
// Date: 2018-11-14
//
// This program simply simulates a first order system, it uses doubles as it's
// data type

#include "first-order.hpp"

#include <iostream>

int main() {
	FirstOrder sys(0.01);

	// step input
	for (int i = 0; i < 10; i++) {
		sys.in(1);
		std::cout << sys.out() << std::endl;
	}
}
