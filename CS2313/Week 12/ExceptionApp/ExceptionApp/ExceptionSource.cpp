
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

double dDivide(int a, int b);
double iDivide(int a, int b);

int main() {
	int number1, number2;
	double dResult;
	double iResult;
	
	cout << "Enter two numbers (Ctrl + Z) to end: ";

	while (cin >> number1 >> number2) {
		//dResult = dDivide(number1, number2);
		//cout << number1 << " / " << number2 << " = " << fixed << setprecision(2) << dResult << endl;

		try {
			iResult = iDivide(number1, number2);
			cout << number1 << " / " << number2 << " = " << iResult << endl;
		}
		catch (invalid_argument& e) {
			cout << e.what() << endl;
		}

		cout << "Enter two numbers (Ctrl + Z) to end: ";
	}
	return 0;
}

double dDivide(int a, int b) {
	return static_cast<double>(a) / b;
}

double iDivide(int a, int b) {
	if (b == 0) {
		throw invalid_argument("An attempt to divide by zero");
	}
	return a / b;
}