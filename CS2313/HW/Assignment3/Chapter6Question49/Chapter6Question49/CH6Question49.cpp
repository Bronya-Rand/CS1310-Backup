
#include <iostream>

using namespace std;

void tripleByReference(int& value); // pass by reference

void tripleByValue(int value) {
	cout << value * 3 << endl;
}

int main() {
	int count{};

	while (count <= 0) {
		cout << "Please enter a positive integer value: ";
		cin >> count;
	}

	cout << "Triple by Value.\n";
	tripleByValue(count);

	cout << "\nTriple by Reference.\n";
	tripleByReference(count);

	cout << count << endl;

	return 0;
}

void tripleByReference(int& value) {
	value *= 3;
}
