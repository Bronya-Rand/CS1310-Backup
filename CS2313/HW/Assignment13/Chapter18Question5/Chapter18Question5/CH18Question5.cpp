
#include <iostream>
#include <sstream>

using namespace std;

/* function template */
template <typename T>
T getAverage(T argA, T argB) {
	T temp = (argA + argB) / 2;
	return temp;
}

/* function template specialization */
template <typename U>
void getAverageMain(U a, U b) {
	U temp = (a + b) / 2;
	cout << "Average of " << a << " and " << b << ": " << temp << endl << endl;
}

int main() {
	cout << "\nNormal Function Template\n\n";
	int a = 5;
	int b = 7;
	cout << "Average of 5 and 7: " << getAverage(a, b) << endl << endl;

	cout << "Function Template Specialization\n\n";
	getAverageMain(5.5, 4.0);
}