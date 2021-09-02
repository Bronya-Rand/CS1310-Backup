
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int a{ 501 };
	int b{ 501 };
	int c{ 501 };
	int i;
	int j;
	int k;

	while (a <= 0 || a > 500) {
		cout << "Type in a whole number for side 1's possibilities: ";
		cin >> a;
	}

	while (b <= 0 || b > 500) {
		cout << "Type in a whole number for side 2's possibilities: ";
		cin >> b;
	}

	while (c <= 0 || c > 500) {
		cout << "Type in a whole number for the hypotenuse's possibilities: ";
		cin >> c;
	}

	cout << setw(5) << "A^2" << setw(20) << "B^2" << setw(20) << "C^2\n";
	cout << "-------------------------------------------------\n";
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= b; j++) {
			for (k = 1; k <= c; k++) {
				if (pow(i, 2) + pow(j, 2) == pow(k, 2)) {
					cout << setw(4) << i << setw(20) << j << setw(19) << k << endl;
				}
			}
		}
	}

	cout << endl;
	return 0;
}