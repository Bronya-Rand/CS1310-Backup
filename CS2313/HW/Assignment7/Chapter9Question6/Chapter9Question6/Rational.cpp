
#include "Rational.h"
#include <sstream>
#include <iomanip>

Rational::Rational(int val1, int val2) :numerator{ val1 }, denominator{ val2 } {
	numerator = val1;
	denominator = val2;

	reducedForm();
}

void Rational::add(int val1, int val2) {
	numerator = numerator + val1;
	denominator = denominator + val2;

	reducedForm();
}

void Rational::subtract(int val1, int val2) {
	numerator = numerator - val1;
	denominator = denominator - val2;

	reducedForm();
}

void Rational::multiply(int val1, int val2) {
	numerator = numerator * val1;
	denominator = denominator * val2;

	reducedForm();
}

void Rational::divide(int val1, int val2) {
	numerator = numerator / val1;
	denominator = denominator / val2;

	reducedForm();
}

std::string Rational::toString() {
	std::ostringstream out;
	out << numerator << "/" << denominator << std::endl;
	return out.str();
}

std::string Rational::toDouble() {
	std::ostringstream out;
	out << std::fixed << std::setprecision(2) << (numerator / 1.0) << "/" << (denominator / 1.0) << std::endl;
	return out.str();
}

void Rational::reducedForm() {
	if (denominator % numerator == 0) {
		denominator = denominator / numerator;
		numerator = numerator / numerator;
	}
}
