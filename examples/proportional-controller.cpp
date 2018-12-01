// Proportional Controller
//
// Author: Matthew Knight
// File Name: proportional-controller.cpp
// Date: 2018-11-30
//
// This program tests a proportional controller.

#include "proportional-controller.hpp"

#include <iostream>

int main() {
	ProportionalController sys(2);

	for (int i = 0; i < 5; i++) {
		sys.in(i,1);
		std::cout << sys.out() << std::endl;
	}
}
