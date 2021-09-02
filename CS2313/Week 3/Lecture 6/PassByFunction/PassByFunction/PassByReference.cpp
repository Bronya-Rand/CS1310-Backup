
#include <iostream>
#include <string>

using namespace std;

void swap(int& x, int& y); // pass by reference

void setName(const string& accountName);

int main() {
	int num1{ 5 };
	int num2{ 10 };

	cout << "Num1 and Num2 before swapping \n\n";
	cout << "Num 1 = " << num1 << endl;
	cout << "Num 2 = " << num2 << endl;

	swap(num1, num2);
	cout << "Num1 and Num2 after swapping \n\n";
	cout << "Num 1 = " << num1 << endl;
	cout << "Num 2 = " << num2 << endl;

	cout << "---------------------------------------------\n";
	string name = "Joyce White";
	cout << name << endl;
	setName(name);
	cout << name << endl;

	return 0;
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

// for performance reasons, strings (and big objects) should be passed by reference
// using const will save you from changing the value of your variables
void setName(const string& accountName) {
	string name{ accountName };
}