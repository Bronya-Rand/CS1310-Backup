
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int hours{ 0 };
	int extra{ 0 };
	double rate{ 0.00 };
	double salary{ 0.00 };

	while (hours != -1) {
		cout << fixed << setprecision(2);

		cout << "Enter hours worked (-1 to end): ";
		cin >> hours;

		if (hours != -1) {

			cout << "Enter hourly rate of the employee ($00.00): ";
			cin >> rate;

			if (hours > 40) {
				extra = hours - 40;
				salary = rate * 40 + (15.00 * extra);
			}
			else {
				salary = rate * hours;
			}
			cout << "Salary is $" << salary << endl << endl;
		}
	}
	return 0;
}