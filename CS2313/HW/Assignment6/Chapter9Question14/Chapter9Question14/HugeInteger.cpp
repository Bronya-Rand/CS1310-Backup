
#include <array>
#include <iostream>
#include <sstream>
#include "HugeInteger.h"

HugeInteger::HugeInteger() {
	for (int i = 0; i < 40; i++) {
		input(i, rand());
	}
}

void HugeInteger::input(int i, int val) {
	integerArray[i] = val;
}

void HugeInteger::output() {
	for (int i = 0; i < 40; i++) {
		std::cout << integerArray[i] << " ";
	}
}

std::string HugeInteger::add(int addBy) {
	std::ostringstream out;
	out << "Adding " << addBy << " to the array is: ";

	for (int i = 0; i < 40; i++) {
		integerArray[i] +=  addBy;
		out << integerArray[i] << " ";
	}

	return out.str();
}

std::string HugeInteger::subtract(int subBy) {
	std::ostringstream out;
	out << "Subtracting " << subBy << " to the array is: ";

	for (int i = 0; i < 40; i++) {
		integerArray[i] -= subBy;
		out << integerArray[i] << " ";
	}

	return out.str();
}
