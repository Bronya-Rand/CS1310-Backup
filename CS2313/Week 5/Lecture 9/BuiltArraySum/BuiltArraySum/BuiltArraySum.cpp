
#include <iostream>

using namespace std;

int arraySum(const int arr[], int size);
int arraySum2(const int* arr, int size);

int main() {
	const int arraySize{ 5 };
	int numbers[arraySize]{ 1, 2, 3, 4, 5 };

	cout << "Total using numbers[] = " << arraySum(numbers, arraySize) << endl;
	cout << "Total using pointers = " << arraySum2(numbers, arraySize) << endl;
	cout << "-------------------------------------------------------------------\n";
	cout << "Number = " << numbers << endl;
	cout << "&numbers[0] = " << &numbers[0] << endl;
	cout << "*numbers = " << *numbers << endl;

	return 0;
}

int arraySum(const int arr[], int size) {
	int total{ 0 };

	for (int i = 0; i < size; i++) {
		total += arr[i];
	}

	return total;
}

int arraySum2(const int* arr, int size) {
	int total{ 0 };

	for (int i = 0; i < size; i++) {
		total += arr[i];
	}

	return total;
}