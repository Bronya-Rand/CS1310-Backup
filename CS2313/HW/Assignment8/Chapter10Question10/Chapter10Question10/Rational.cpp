
#include "Rational.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

Rational::Rational(int val1, int val2) :numerator{ val1 }, denominator{ val2 } {
	if (val2 == 0) {
		throw std::invalid_argument("Denominator cannot have value of 0.");
	}
	else if (val2 < 0) {
		throw std::invalid_argument("Denominator cannot be negative.");
	}
	else {
		numerator = val1;
		denominator = val2;
	}

	reducedForm();
}

Rational Rational::operator+(Rational& c) {
	Rational temp{ *this };
	temp.numerator += c.numerator;
	temp.denominator += c.denominator;
	return temp;
}

Rational Rational::operator-(Rational& c) {
	Rational temp{ *this };
	temp.numerator -= c.numerator;
	temp.denominator -= c.denominator;
	return temp;
}

Rational Rational::operator*(Rational& c) {
	Rational temp{ *this };
	temp.numerator *= c.numerator;
	temp.denominator *= c.denominator;
	return temp;
}

Rational Rational::operator/(Rational& c) {
	Rational temp{ *this };
	temp.numerator /= c.numerator;
	temp.denominator /= c.denominator;
	return temp;
}

bool Rational::operator==(const Rational& c) {
	Rational temp{ *this };
	return (temp.numerator == c.numerator) && (temp.denominator == c.denominator);
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
