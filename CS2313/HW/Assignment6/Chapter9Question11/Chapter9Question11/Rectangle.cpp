
#include "Rectangle.h"
#include <stdexcept>
#include <sstream>

Rectangle::Rectangle(float l, float w) {
	if (l > 0.0 || l < 20.0) {
		length = l;
	}
	else {
		throw std::invalid_argument("Invalid length. Length must be > 0.0 or < 20.0");
	}

	if (w > 0.0 || w < 20.0) {
		width = w;
	}
	else {
		throw std::invalid_argument("Invalid width. Width must be > 0.0 or < 20.0");
	}
}

float Rectangle::getLength() {
	return length;
}

float Rectangle::getWidth() {
	return width;
}

void Rectangle::setLength(float l) {
	if (l > 0.0 && l < 20.0) {
		length = l;
	}
	else {
		throw std::invalid_argument("Invalid length. Length must be > 0.0 or < 20.0");
	}
}

void Rectangle::setWidth(float w) {
	if (w > 0.0 && w < 20.0) {
		width = w;
	}
	else {
		throw std::invalid_argument("Invalid width. Width must be > 0.0 or < 20.0");
	}
}

std::string Rectangle::getPerimeter() {
	std::ostringstream out;
	out << "The perimeter of your rectangle with length " << length << " and width " << width << " is: " << (length * 2.0) + (width * 2.0) << std::endl;
	return out.str();
}
std::string Rectangle::getArea() {
	std::ostringstream out;
	out << "The area of your rectangle with length " << length << " and width " << width << " is: " << length * width << std::endl;
	return out.str();
}