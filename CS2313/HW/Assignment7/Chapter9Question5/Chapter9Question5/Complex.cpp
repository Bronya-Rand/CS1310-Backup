
#include <sstream>
#include <cmath>
#include "Complex.h"

Complex::Complex(double realNum1, double realNum2, double imaginaryNum1, double imaginaryNum2) :value1{ realNum1 }, value2{ realNum2 }, iValue1{ imaginaryNum1 }, iValue2{ imaginaryNum2 } {
	value1 = realNum1;
	value2 = realNum2;
	iValue1 = imaginaryNum1;
	iValue2 = imaginaryNum2;
}

double Complex::add() {
	return ((value1 + value2) + (iValue1 + iValue2));
}

double Complex::subtract() {
	return ((value2 - value1) - (iValue2 - iValue1));
}

std::string Complex::toString() {
	std::ostringstream out;
	out << "(" << value1 + value2 << ", " << iValue1 + iValue2 << ")\n";
	return out.str();
}
