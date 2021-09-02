
#include <iostream>

using namespace std;

int main() {
	int binary{ 0 };
	int power{ 1 };
	int lastDigit{ 0 };
	int decimal{ 0 };

	cout << "Enter a binary number: ";
	cin >> binary;

	// based off code from GeeksForGeeks.com
	while (binary) {
		lastDigit = binary % 10;
		binary = binary / 10;

		decimal += lastDigit * power;

		power = power * 2;
	}

	cout << "The decimal equivalent to: " << decimal << endl;
	return 0;
}