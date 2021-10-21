
#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

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

istream& operator>>(istream& input, Complex& c) {
	input >> c.value1 >> c.value2 >> c.iValue1 >> c.iValue2;
	return input;
}

ostream& operator<<(ostream& output, const Complex& c) {
	output << "(" << c.value1 + c.value2 << ", " << c.iValue1 + c.iValue2 << ")\n";
	return output;
}

Complex Complex::operator*(const Complex& c) {
	Complex temp{ *this };
	temp.value1 *= c.value1;
	temp.value2 *= c.value2;
	temp.iValue1 *= c.iValue1;
	temp.iValue2 *= c.iValue2;
	return temp;
}

bool Complex::operator==(const Complex& c) {
	Complex temp{ *this };
	return (temp.value1 == c.value1) && (temp.value2 == c.value2) && (temp.iValue1 == c.iValue1) && (temp.iValue2 == c.iValue2);
}

bool Complex::operator!=(const Complex& c) {
	Complex temp{ *this };
	return (temp.value1 != c.value1) && (temp.value2 != c.value2) && (temp.iValue1 != c.iValue1) && (temp.iValue2 != c.iValue2);
}
