
#include <string>

#ifndef COMP_H
#define COMP_H

class Complex {
public:
	Complex(double realNum1, double realNum2, double imaginaryNum1, double imaginaryNum2);
	std::string add();
	std::string subtract();
	std::string toString();
private:
	double value1;
	double value2;
	double iValue1;
	double iValue2;
};

#endif