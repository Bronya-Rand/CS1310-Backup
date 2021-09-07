
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


string isPerfect(int digit) {
	int total{ 0 };

	for (int x = 1; x < digit; x++) {
		if (digit % x == 0) {
			total += x;
		}
	}
	if (digit == total) {
		return "Yes";
	}
	else {
		return "No";
	}
}

int main() {	
	cout << "Number" << setw(20) << "Perfect?\n";
	for (int x = 1; x <= 1000; x++) {
		cout << left << setw(20) << x << isPerfect(x) << endl;
	}
	return 0;
}