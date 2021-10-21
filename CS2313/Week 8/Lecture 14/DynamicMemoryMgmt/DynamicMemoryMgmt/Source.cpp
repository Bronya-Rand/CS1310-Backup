
#include <iostream>

using namespace std;

int main() {

	int* intPtr = new int{ 20 };
	cout << *intPtr << endl;
	delete intPtr;

	cout << "-----------------------------\n";

	int* grades = new int[5]{ 10, 20, 30, 40, 50 };
	for (int i = 0; i < 5; i++) {
		cout << grades[i] << endl;
	}
	delete[] grades;

	return 0;
}