
#include <iostream>

using namespace std;

int main() {
	int number{ 0 };
	int counter{ 0 };
	bool palindrone = false;

	while (number < 10000 || number > 99999) {
		cout << "Enter a 5-digit number: ";
		cin >> number;
	}

	if (number / 10000 == ((((number % 10000) % 1000) % 100) % 10)) {
		if (((number % 10000) / 1000) == ((((number % 10000) % 1000) % 100) / 10)) {
			palindrone = true;
		}
	}

	if (palindrone == true) {
		cout << "This number is a palindrome.\n";
	}
	else {
		cout << "This number is not a palindrome.\n";
	}
	return 0;
}