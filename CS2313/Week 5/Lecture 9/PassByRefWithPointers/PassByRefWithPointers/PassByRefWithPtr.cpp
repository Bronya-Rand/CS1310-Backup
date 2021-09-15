
#include <iostream>
#include <ctime>

using namespace std;

void swap1(int& x, int& y);
void swap2(int* x, int* y);

int main() {
	int num1{ 5 };
	int num2{ 10 };

	cout << "Before Swap:\n";
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	cout << "After Swap:\n";

	//swap1(num1, num2);
	swap2(&num1, &num2);

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	return 0;
}

void swap1(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap2(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}