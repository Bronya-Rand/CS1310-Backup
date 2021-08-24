/*
Chapter 2 Question 19
Author: Azariel Del Carmen
*/

#include <iostream>

using namespace std;

int main() {

	int x{};
	int y{};
	int z{};
	int result{};

	cout << "Input three different integers: ";
	cin >> x >> y >> z;

	result = x + y + z;
	cout << "Sum is " << result << endl;

	result = (x + y + z) / 3;
	cout << "Average is " << result << endl;

	result = x * y * z;
	cout << "Product is " << result << endl;

	if (x < y && x < z) {
		result = x;
	}
	else if (x > y && y > z) {
		result = z;
	}
	else if (x < y && x > z) {
		result = z;
	}
	else {
		result = y;
	}

	cout << "Smallest is " << result << endl;

	if (x > y && x > z) {
		result = x;
	}
	else if (x > y && x < z) {
		result = z;
	}
	else if (x < y && y > z) {
		result = y;
	}
	else {
		result = z;
	}
	cout << "Biggest is " << result << endl;
}