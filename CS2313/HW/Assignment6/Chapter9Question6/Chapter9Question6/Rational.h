
#include <string>

#ifndef RAT_H
#define RAT_H

class Rational {
public:
	Rational(int val1, int val2);
	void add(int val1, int val2);
	void subtract(int val1, int val2);
	void multiply(int val1, int val2);
	void divide(int val1, int val2);
	std::string toString();
	std::string toDouble();
	void reducedForm();
private:
	int numerator;
	int denominator;
};

#endif