
#include <iostream>
#include <array>

using namespace std;

const int rows{ 2 };
const int columns{ 3 };

void printArray1(const array<array<int, columns>, rows>& a);
void printArray2(const array<array<int, columns>, rows>& a);

int main() {
	int arr[rows][columns];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;

	cout << "--------------- Simple 2D Array ----------------\n";

	int total{ 0 };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << arr[i][j] << " ";
			total += arr[i][j];
		}
	}

	cout << "\nTotal = " << total << endl;

	cout << "--------------- 2D Array using class template <array> ----------------\n";

	//array<array<int, columns>, rows> arr2{ 1, 2, 3, 4, 5, 6 };

	array<array<int, columns>, rows> arr2{{
											{1, 2, 3},
											{4, 5, 6}
										}};

	printArray1(arr2);
	cout << endl << endl;
	printArray2(arr2);

	return 0;
}

void printArray1(const array<array<int, columns>, rows>& a) {
	int total = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << a[i][j] << " ";
			total += a[i][j];
		}
	}

	cout << "\nTotal = " << total << endl;
}

void printArray2(const array<array<int, columns>, rows>& a) {
	int total = 0;

	for (const auto& row: a) {
		for (const auto& item: row) {
			cout << item << " ";
			total += item;
		}
	}

	cout << "\nTotal = " << total << endl;
}