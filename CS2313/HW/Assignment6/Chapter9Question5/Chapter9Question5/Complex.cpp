
#include <sstream>
#include "Complex.h"

Complex::Complex(double realNum1, double realNum2, double imaginaryNum1, double imaginaryNum2) :value1{ realNum1 }, value2{ realNum2 }, iValue1{ imaginaryNum1 }, iValue2{ imaginaryNum2 } {
	value1 = realNum1;
	value2 = realNum2;
	iValue1 = imaginaryNum1;
	iValue2 = imaginaryNum2;
}

std::string Complex::add() {
	std::ostringstream out;
	out << "Adding (" << value1 << " + " << value2 << ") with (" << iValue1 << " + " << iValue2 << ") * i = " << (value1 + value2) << " + " << (iValue1 + iValue2) << "i\n";
	return out.str();
}

std::string Complex::subtract() {
	std::ostringstream out;
	out << "Subtracting (" << value2 << " - " << value1 << ") with (" << iValue2 << " - " << iValue1 << ") * i = " << (value2 - value1) << " - " << (iValue2 - iValue1) << "i\n";
	return out.str();
}

std::string Complex::toString() {
	std::ostringstream out;
	out << "(" << value1 + value2 << ", " << iValue1 + iValue2 << ")\n";
	return out.str();
}
