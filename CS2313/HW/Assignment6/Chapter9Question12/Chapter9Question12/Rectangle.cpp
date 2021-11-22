
#include "Rectangle.h"
#include <stdexcept>
#include <sstream>

Rectangle::Rectangle(float len1, float len2, float wid1, float wid2) {
	setDimensions(len1, len2, wid1, wid2);
}

float Rectangle::getLength() {
	return (length1 + length2);
}

float Rectangle::getWidth() {
	return (width1 + width2);
}

void Rectangle::setDimensions(float l1, float l2, float w1, float w2) {
	if (l1 > 0.0 || l1 < 20.0) {
		length1 = l1;
	}
	else {
		throw std::invalid_argument("Invalid 1st length. Length must be > 0.0 or < 20.0");
	}

	if (l2 > 0.0 || l2 < 20.0) {
		length2 = l2;
	}
	else {
		throw std::invalid_argument("Invalid 2nd length. Length must be > 0.0 or < 20.0");
	}

	if (w1 > 0.0 || w1 < 20.0) {
		width1 = w1;
	}
	else {
		throw std::invalid_argument("Invalid 1st width. Width must be > 0.0 or < 20.0");
	}

	if (w2 > 0.0 || w2 < 20.0) {
		width2 = w2;
	}
	else {
		throw std::invalid_argument("Invalid 2nd width. Width must be > 0.0 or < 20.0");
	}

	if (!(l1 == w1 && l2 == w2) && !(l1 == w2 && l2 == w1) && !(l1 == l2 && w1 == w2)) {
		throw std::invalid_argument("These variables do not make a rectangle.");
	}
}

std::string Rectangle::getPerimeter() {
	std::ostringstream out;
	out << "The perimeter of your rectangle with length " << length1 << " and " << length2 << " and width " << width1 << " and " << width2 << " is: " << (length1 + length2) + (width1 + width2) << std::endl;
	return out.str();
}
std::string Rectangle::getArea() {
	std::ostringstream out;
	out << "The area of your rectangle with length " << length1 << " and " << length2 << " and width " << width1 << " and " << width2 << " is: " << (length1 + length2) * (width1 + width2) << std::endl;
	return out.str();
}