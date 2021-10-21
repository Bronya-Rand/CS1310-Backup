
#include <iostream>
#include "Rational.h"

using namespace std;

int main() {

	Rational r1(2, 4);
	Rational r2(4, 1);
	std::cout << "Current Numerator/Denominator for r1: " << r1.toString() << endl;
	std::cout << "Current Numerator/Denominator for r2: " << r2.toString() << endl;
	r1 = r1 + r2;
	std::cout << "Added r2 to r1. r1 is now: " << r1.toString();
	std::cout << "Numerator/Denominator (double): " << r1.toDouble();
	r1 = r1 - r2;
	std::cout << "Subtracted r2 to r1. r1 is now: " << r1.toString();
	r1 = r1 * r2;
	std::cout << "Multiplied r2 to r1. r1 is now: " << r1.toString();
	r1 = r1 / r2;
	std::cout << "Divided r2 to r1. r1 is now: " << r1.toString();
	std::cout << "Equal?: " << (r1 == r2) << endl;

	return 0;
}
