
#include <iostream>
#include <array>

using namespace std;

int main() {
	unsigned short int A[] = { 1, 7, 5, 13 };
	//unsigned short int A[]{ 1, 7, 5, 13 };

	cout << A[0] << endl;
	cout << A[1] << endl;
	cout << A[2] << endl;
	cout << A[3] << endl;
	//cout << A[4] << endl; security issue

	cout << "-----------------------------------------------\n";
	array<int, 4> A2 = { 11, 22, 33, 44 };
	cout << A2[0] << endl;
	cout << A2[1] << endl;
	cout << A2[2] << endl;
	cout << A2[3] << endl;
	//cout << A2[4] << endl; runtime error

	cout << "-----------------------------------------------\n";
	array<int, 4> A3 = {};

	cout << A3[0] << endl;
	cout << A3[1] << endl;
	cout << A3[2] << endl;
	cout << A3[3] << endl;

	cout << "-----------------------------------------------\n";
	const size_t arraySize{ 5 };
	array<int, arraySize> arr;

	for (size_t i{ 0 }; i < arr.size(); i++) {
		arr[i] = i * 2;
	}

	return 0;
}