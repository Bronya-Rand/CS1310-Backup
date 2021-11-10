
#include <iostream>

using namespace std;

template <typename T>

T maximum(T val1, T val2, T val3) {
	T maxValue = val1;

	if (val2 > maxValue) {
		maxValue = val2;
	}

	if (val3 > maxValue) {
		maxValue = val3;
	}

	return maxValue;
}

/*int maximum(int val1, int val2, int val3) {
	int maxValue = val1;

	if (val2 > maxValue) {
		maxValue = val2;
	}

	if (val3 > maxValue) {
		maxValue = val3;
	}

	return maxValue;
}

double maximum(double val1, double val2, double val3) {
	double maxValue = val1;

	if (val2 > maxValue) {
		maxValue = val2;
	}

	if (val3 > maxValue) {
		maxValue = val3;
	}

	return maxValue;
}

char maximum(char val1, char val2, char val3) {
	char maxValue = val1;

	if (val2 > maxValue) {
		maxValue = val2;
	}

	if (val3 > maxValue) {
		maxValue = val3;
	}

	return maxValue;
}*/

int main() {
	cout << "Maximum (12, 7, 4) = " << maximum(12, 7, 4) << endl;
	cout << "Maximum (12.4, 7.6, 4.32) = " << maximum(12.4, 7.6, 4.32) << endl;
	cout << "Maximum ('D', 'L', 'S') = " << maximum('D', 'L', 'S') << endl;
	return 0;
}