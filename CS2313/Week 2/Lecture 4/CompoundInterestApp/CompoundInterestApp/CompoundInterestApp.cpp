
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	
	double principal{ 1000.00 };
	double rate{ 0.05 };

	cout << fixed << setprecision(2);

	cout << "Initial Principal: " << principal << endl;
	cout << "    Interest Rate: " << rate << endl;

	cout << "Year" << setw(20) << "Balance" << endl;

	for (unsigned int year{ 1 }; year <= 10; year++) {
		double balance = principal * pow(1 + rate, year);
		cout << setw(4) << year << setw(20) << balance << endl;
	}
	
	return 0;
}