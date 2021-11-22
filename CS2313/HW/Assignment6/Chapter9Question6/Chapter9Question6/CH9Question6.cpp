
#include <iostream>
#include "Rational.h"

using namespace std;

int main() {

	Rational r1 (2, 4);
	std::cout << "Current Numerator/Denominator: " << r1.toString();
	r1.add(10, 13);
	std::cout << "Added (10, 13): " << r1.toString();
	std::cout << "Numerator/Denominator (double): " << r1.toDouble();
	r1.subtract(2, 1);
	std::cout << "Subtracted (2, 1): " << r1.toString();
	r1.multiply(3, 3);
	std::cout << "Multiplied (3, 3): " << r1.toString();
	r1.divide(2, 2);
	std::cout << "Divided (2, 2): " << r1.toString();

	return 0;
}
