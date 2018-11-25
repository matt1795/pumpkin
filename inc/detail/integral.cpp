// Integral "System"
//
// Author: Matthew Knight
// File Name: integral.hpp
// Date: 2018-11-25
//
// This class implements an integral operation, it is mostly intended for system
// composing. Instead of using a rectangular based integrating method, this one
// uses a triangle method to better approximate the input signal.

// pass period as parameter
template <typename T, size_t Order>
Integral<T, Order>::Integral(double period) : period(period) {}

// input new value
template <typename T, size_t Order>
void Integral<T, Order>::in(T val) {
	// rotate everything
	for (size_t i = 0; i < arr.size(); i++) {
		arr[i][1] = arr[i][0];
	}

	// input new value
	arr[0][0] = val;

	// calculate new values
	for (size_t i = 1; i < arr.size(); i++)
		arr[i][0] += (period / 2) * (arr[i-1][0] + arr[i-1][1]);
}

// return output
template <typename T, size_t Order>
T Integral<T, Order>::out() {
	return arr.back()[0];
}

// access specific integration
template <typename T, size_t Order>
T& Integral<T, Order>::operator[](size_t index) {
	return arr[index][0];
}
