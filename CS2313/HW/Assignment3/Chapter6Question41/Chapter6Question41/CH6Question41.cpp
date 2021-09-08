
#include <iostream>

using namespace std;

int gcd(int one, int two) {

	if (two == 0) {
		return one;
	}

	return gcd(two, one % two);
}

int main() {
	int digitOne{};
	int digitTwo{};

	while (digitOne <= 0) {
		cout << "Please enter the first integer: ";
		cin >> digitOne;
	}

	while (digitTwo <= 0) {
		cout << "Please enter the second integer: ";
		cin >> digitTwo;
	}

	if (digitOne < digitTwo) {
		cout << "ERROR: First digit must be greater than the second digit.\n";
		return -1;
	}

	cout << "The GCD between " << digitOne << " and " << digitTwo << " is " << gcd(digitOne, digitTwo) << endl;
	return 0;
}