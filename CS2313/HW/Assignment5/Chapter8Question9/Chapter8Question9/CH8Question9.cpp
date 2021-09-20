
#include <iostream>

using namespace std;

int main() {
	long value1{200000};
	long value2{};
	long* longPtr{ nullptr };

	longPtr = &value1;

	cout << "Value of value1 via longPtr: " << *longPtr << endl;
	value2 = *longPtr;
	cout << "Value of value2: " << value2 << endl;
	cout << "Address of value1: " << &value1 << endl;
	cout << "Address of longPtr: " << &*longPtr << endl;
	cout << "Address of longPtr equal to address of value1?: " << (&*longPtr == &value1) << endl;
}