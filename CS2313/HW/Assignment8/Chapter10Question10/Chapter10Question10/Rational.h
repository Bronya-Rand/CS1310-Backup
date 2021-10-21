
#include <string>

#ifndef RAT_H
#define RAT_H

class Rational {
public:
	Rational(int val1, int val2);
	Rational operator+(Rational& c);
	Rational operator-(Rational& c);
	Rational operator*(Rational& c);
	Rational operator/(Rational& c);
	bool operator==(const Rational& c);
	std::string toString();
	std::string toDouble();
	void reducedForm();
private:
	int numerator;
	int denominator;
};

#endif#pragma once
