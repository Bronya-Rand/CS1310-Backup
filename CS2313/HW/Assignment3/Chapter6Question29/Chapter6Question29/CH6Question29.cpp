
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

string isPrime(int digit) {
	if (digit % 2 == 1) {
		return "Yes";
	}
	else {
		return "No";
	}
}

int main() {
	cout << sqrt(2) << endl;
	cout << left << setw(20) << "Digit" << "Prime?\n";
	for (int x = 2; x <= sqrt(10000); x++) {
		cout << left << setw(20) << x << isPrime(x) << endl;
	}
	return 0;
}