// FIR Filter Program
//
// Author: Matthew Knight
// File Name: fir-filter.cpp
// Date: 2018-11-04
//
// This program accepts arguments which configure an integer based FIR filter 
// and applies the filter on values coming in through stdin, and outputs them to
// stdout.

#include "fir.hpp"

#include <iostream>
#include <limits>
#include <vector>

int main(int argc, char *argv[]) {
	std::vector<int> weights(4, 1);
	FIR<int> filter(weights);

	for (int i = 0; i < 10; i++) {
		if (i == 0)
			filter.in(1);
		else
			filter.in(0);

		std::cout << filter.out() << std::endl;
	}
}
