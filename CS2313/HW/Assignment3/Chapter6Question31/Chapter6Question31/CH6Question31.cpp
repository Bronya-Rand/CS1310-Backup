
#include <iostream>

using namespace std;

int gcd(int one, int two) {
	int gcd{};
	int lesser{};

	if (one > two) {
		lesser = two;
	}
	else {
		lesser = one;
	}

	for (int x = 1; x < lesser; x++) {
		if (one % x == 0 && two % x == 0) {
			gcd = x;
		}
	}
	
	return gcd;
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

	cout << "The GCD between " << digitOne << " and " << digitTwo << " is " << gcd(digitOne, digitTwo) << endl;
	return 0;
}