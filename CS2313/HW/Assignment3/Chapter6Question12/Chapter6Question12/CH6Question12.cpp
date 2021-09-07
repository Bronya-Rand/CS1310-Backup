
#include <iostream>
#include <iomanip>

using namespace std;

double calculateCharges(double hours) {
	double total{ 20.00 };
	
	if (hours > 3) {

		if (hours >= 24) {
			total = 50.00;
		}
		else {
			total += (5.00 * (hours - 3));
		}
	}

	return total;
}

int main() {
	double carHours[3] = { 0.0, 0.0, 0.0 };
	double charges[3] = { 0.0, 0.0, 0.0 };
	double culmativeHours{ 0.0 };
	double culmativeCharges{ 0.0 };
	int x = 1;

	cout << fixed << setprecision(2);

	while (x <= 3) {
		cout << "Enter the car hours for Car " << x << ": ";
		cin >> carHours[x - 1];

		if (carHours[x - 1] < 0.0) {
			cout << "Invalid hours have been entered. Please try again.\n\n";
		}
		else {
			culmativeHours += carHours[x - 1];
			charges[x - 1] = calculateCharges(carHours[x - 1]);
			culmativeCharges += calculateCharges(carHours[x - 1]);
			x++;
		}
	}

	cout << "Car" << setw(20) << "Hours" << setw(20) << "Charge\n";
	for (int i = 1; i <= 3; i++) {
		cout << i << setw(22) << carHours[i - 1] << setw(19) << charges[i - 1] << endl;
	}
	cout << "TOTAL" << setw(18) << culmativeHours << setw(19) << culmativeCharges << endl;

	return 0;
}