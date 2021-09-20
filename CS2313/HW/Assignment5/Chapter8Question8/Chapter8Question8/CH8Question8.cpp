
#include <iostream>

using namespace std;

int main() {
	unsigned int values[5]{ 2, 4, 6, 8, 10 };
	unsigned int* vPtr{ nullptr };
	int i;

	cout << "Array via Array Subscript:";
	for (i = 1; i <= 5; i++) {
		cout << " " << values[i - 1];
	}
	cout << endl;

	vPtr = values;
	//vPtr = &values[0]; 2nd statement?

	cout << "Array via Pointer Offset:";
	for (i = 1; i <= 5; i++) {
		cout << " " << *vPtr + (i - 1);
	}
	cout << endl;

	cout << "Array via Array Pointer Subscript:";
	for (i = 1; i <= 5; i++) {
		cout << " " << *(values + (i - 1));
	}
	cout << endl;

	cout << "Array via Pointer Subscript:";
	for (i = 1; i <= 5; i++) {
		cout << " " << vPtr[i - 1];
	}
	cout << endl << endl;

	cout << "values[5] as Array Subscript: " << values[4] << endl;
	cout << "values[5] as Pointer Offset: " << *(vPtr + 4) << endl;
	cout << "values[5] as Array Pointer Subscript: " << *(values + 4) << endl;
	cout << "values[5] as Pointer Subscript: " << vPtr[4] << endl;
	cout << "Address referenced by vPtr + 3: " << &*(vPtr + 3) << endl;
}