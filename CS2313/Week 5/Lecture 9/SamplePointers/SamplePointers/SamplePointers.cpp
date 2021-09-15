
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int x = 7;

	cout << left << setw(30) << "Value of x = " << x << endl;
	cout << left << setw(30) << "Address of x = " << &x << endl;

	int* y = nullptr; //pointer but this pointer is pointing to nothing

	cout << left << setw(30) << "Value of y = " << y << endl;
	cout << left << setw(30) << "Address of y = " << &y << endl;

	cout << "---------------------------------------------------------\n";

	y = &x;
	cout << left << setw(30) << "Value of y = " << y << endl;
	cout << left << setw(30) << "Address of y = " << &y << endl;

	cout << left << setw(30) << "The value referenced by y" << *y << endl;

	*y = 15;
	cout << left << setw(30) << "Value of x = " << x << endl;

	cout << "---------------------------------------------------------\n";

	int* ptr = new int;
	*ptr = 55;

	cout << left << setw(30) << "Value of ptr = " << ptr << endl;
	cout << left << setw(30) << "Address of ptr = " << &ptr << endl;
	cout << left << setw(30) << "Value of ptr = " << *ptr << endl;

	cout << "---------------------------------------------------------\n";

	int num = 11;
	int& refNum = num; //reference variable

	cout << left << setw(30) << "Value of refNum = " << refNum << endl;
	cout << left << setw(30) << "Address of num = " << &num << endl;
	cout << left << setw(30) << "Address of refNum = " << &refNum << endl;

	return 0;
}