
#include <iostream>
#include "Complex.h"

int main() {

	Complex c1(2, 4, 1, 3);
	std::cout << "Current Values: " << c1 << std::endl;
	std::cout << "Enter 4 integer values: ";
	std::cin >> c1;
	Complex c2(5, 3, 1, 9);
	std::cout << "Current Values for c2: " << c2 << std::endl;
	std::cout << "Multiplying by 3: " << c1 * c2 << std::endl;
	std::cout << "Equal?: " << (c1 == c2) << std::endl;
	std::cout << "Not Equal?: " << (c1 != c2) << std::endl;
	return 0;
}