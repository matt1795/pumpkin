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
	SISO<int>::Ptr filter1(new FIR<int>({ 1, 2, 3, 4 }));
	SISO<int>::Ptr filter2(new FIR<int>({ 1, 2, 3, 4 }));
	SISO<int>::Ptr filter3(new FIR<int>({ 1, 2, 3, 4 }));
	SISO<int>::Ptr parallel(new Parallel<int>({ filter1, filter2 }));
	SISO<int>::Ptr cascade(new Cascade<int>({ filter3, parallel }));
	cascade->stream(std::cin, std::cout);
}
