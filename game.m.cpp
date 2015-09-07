// game.m.cpp

#include "src/game.h"
#include <cmath>
#include <iostream>

// Random unit test function A.
double square(double root) {
	return root * root;
}

// Random unit test function B.
double squareRoot(double value) {
	return sqrt(value);
}

int main(int argc, char *argv[]) {
	using namespace StevensDev;
	std::cout << square(9.0) << std::endl;
	std::cout << "Howdy." << std::endl;
	return 0;
}