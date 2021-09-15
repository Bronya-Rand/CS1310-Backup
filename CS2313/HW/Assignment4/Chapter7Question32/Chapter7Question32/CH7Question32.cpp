
#include <iostream>

using namespace std;

int minValue(const int val[], int size) {
	int min{ val[0] };

	for (int i = 1; i < size; i++) {
		if (val[i] < min) {
			min = val[i];
		}
	}

	return min;
}

int main() {
	int count{ 1 };
	int value{};
	const size_t arraySize{ 8 };
	int uniqueArray[arraySize]{ 0, 0, 0, 0, 0, 0, 0, 0};

	cout << "You will be typing in 8 integers into a array for minimum calculation.\n\n";

	while (count <= 8) {
		cout << "Please enter integer " << count << "'s value: ";
		cin >> value;

		uniqueArray[count - 1] = value;
		count++;
	}

	cout << "\nThe minimum integer in your array was: " << minValue(uniqueArray, arraySize) << endl;

	return 0;
}