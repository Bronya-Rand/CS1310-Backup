
#include <iostream>
#include <stdexcept>

using namespace std;

int iDivide(int a, int b);
int myFunction(int a, int b);

int main() {
	int number1, number2;
	int iResult;
	cout << "Enter two numbers (Ctrl+Z to end): ";

	while (cin >> number1 >> number2) {
		try {
			iResult = myFunction(number1, number2);
			cout << number1 << " / " << number2 << " = " << iResult << endl;
		}
		catch (logic_error& e) {
			cout << e.what() << endl;
		}
		cout << "Enter two numbers (Ctrl+Z to end): ";
	}
	return 0;
}

int iDivide(int a, int b) {
	if (b == 0) {
		throw invalid_argument("Attempt to divide by zero.");
	}
	return a / b;
}

int myFunction(int a, int b) {
	try {
		int iResult = iDivide(a, b);
	}
	catch (logic_error& e) {
		throw;
	}
}