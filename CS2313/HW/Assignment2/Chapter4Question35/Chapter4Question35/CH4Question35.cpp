
#include <iostream>

using namespace std;

int main() {
	char input{'a'};
	int factorial{ 0 };
	int m{ 1 };
	int total{ 1 };

	while (input != 'e' && input != 'E' && input != 'n' && input != 'N') {
		cout << "Do you want to factorial e/e^x or factorial a number? (e/n): ";
		cin >> input;
	}

	if (input == 'n' || input == 'N') {
		cout << "Enter a whole number: ";
		cin >> factorial;

		while (m <= factorial) {
			total = total * m;
			m++;
		}
		cout << endl << "The factorial value totals up to: " << total << endl;
	}
	else {
		cout << "How accurate do you want e to be? (whole numbers only): ";
		cin >> factorial;

		cout << "e = 1";
		while (m <= factorial) {
			cout << " + " << "1/" << m << "!";
			m++;
		}

		cout << endl << endl;
		m = 1;

		cout << "How accurate do you want e^x to be? (whole numbers only): ";
		cin >> factorial;

		cout << "e^x = 1";
		while (m <= factorial) {
			cout << " + " << "x/" << m << "!";
			m++;
		}
		cout << endl;
	}

	return 0;
}