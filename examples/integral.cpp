// Integral test

#include "integral.hpp"

#include <iostream>

int main() {
	// period of one
	Integral<double, 1> integral(1);

	for (int i = 0; i < 10; i++) {
		integral.in(1);
		std::cout << integral.out() << std::endl;
	}
}
