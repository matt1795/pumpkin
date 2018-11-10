// FIR Filter Program
//
// Author: Matthew Knight
// File Name: fir-filter.cpp
// Date: 2018-11-04
//
// This program accepts arguments which configure an integer based FIR filter 
// and applies the filter on values coming in through stdin, and outputs them to
// stdout.

#include "cascade.hpp"
#include "fir.hpp"
#include "parallel.hpp"

#include <iostream>
#include <limits>
#include <vector>

int main(int argc, char *argv[]) {
	auto filter1 = new FIR<int>({ 1, 2, 3, 4 });
	auto filter2 = new FIR<int>({ 1, 2, 3, 4 });
	auto filter3 = new FIR<int>({ 1, 2, 3, 4 });
	std::vector<SISO<int>*> systems { filter1, filter2 };
	Parallel<int> parallel({ filter1, filter2 });
	Cascade<int> cascade({ filter3, &parallel });
	cascade.stream(std::cin, std::cout);
}
