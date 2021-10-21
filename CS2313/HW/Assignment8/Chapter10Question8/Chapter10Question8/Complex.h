
#include <sstream>

#ifndef COMP_H
#define COMP_H

class Complex {
	friend std::istream& operator>>(std::istream& input, Complex& c);
	friend std::ostream& operator<<(std::ostream& output, const Complex& c);
public:
	Complex(double realNum1, double realNum2, double imaginaryNum1, double imaginaryNum2);
	double add();
	double subtract();
	std::istream& operator>>(const Complex& c);
	std::ostream& operator<<(const Complex& c);
	Complex operator*(const Complex& c);
	bool operator==(const Complex& c);
	bool operator!=(const Complex& c);
private:
	double value1;
	double value2;
	double iValue1;
	double iValue2;
};

#endif