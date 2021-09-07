
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double x{};

	cout << fixed << setprecision(2);

	x = fabs(7.5);
	cout << "Fabs: " << x << endl << endl;

	x = floor(7.5);
	cout << "Floor: " << x << endl << endl;

	x = fabs(0.0);
	cout << "Fabs: " << x << endl << endl;

	x = ceil(0.0);
	cout << "Ceil: " << x << endl << endl;

	x = fabs(-6.4);
	cout << "Fabs: " << x << endl << endl;

	x = ceil(-6.4);
	cout << "Ceil: " << x << endl << endl;

	x = ceil(-fabs(-8 + floor(-5.5)));
	cout << "Ceil(-Fabs(-8 + Floor)): " << x << endl << endl;

	return 0;
}