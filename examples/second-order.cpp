// second order test

#include "second-order.hpp"

#include <iostream>

int main() {
	SecondOrder sys(0.2, 200);

	for (int i = 0; i < 1000; i++) {
		sys.in(1);
		std::cout << sys.out() << std::endl;
	}
}
