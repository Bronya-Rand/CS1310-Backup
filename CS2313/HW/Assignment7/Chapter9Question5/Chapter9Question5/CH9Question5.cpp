
#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

	Complex c1(2, 4, 1, 3);
	std::cout << "Current Values: " << c1.toString();
	std::cout << "Adding Real & Imaginary Numbers: " << c1.add() << std::endl;
	std::cout << "Subtracting Real & Imaginary Numbers: " << c1.subtract() << std::endl;
	return 0;
}