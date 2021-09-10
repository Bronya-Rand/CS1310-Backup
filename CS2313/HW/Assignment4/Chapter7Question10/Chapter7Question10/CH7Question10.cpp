
#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int getSalary() {

	int salary{};
	
	cout << "What was your salary as of today [$200 and above]? (-1 to exit): ";
	cin >> salary;

	return salary;
}

int main() {

	const size_t counterSize{ 9 };
	array<int, counterSize> counter{ 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int submission{};

	submission = getSalary();
	while (submission != -1) {
		if (submission < 200) {
			cout << "Invalid Salary. Valid salaries must be greater than or equal to $200.\n";
		}
		else if (submission >= 200 && submission < 300) {
			counter[0] += 1;
		}
		else if (submission >= 300 && submission < 400) {
			counter[1] += 1;
		}
		else if (submission >= 400 && submission < 500) {
			counter[2] += 1;
		}
		else if (submission >= 500 && submission < 600) {
			counter[3] += 1;
		}
		else if (submission >= 600 && submission < 700) {
			counter[4] += 1;
		}
		else if (submission >= 700 && submission < 800) {
			counter[5] += 1;
		}
		else if (submission >= 800 && submission < 900) {
			counter[6] += 1;
		}
		else if (submission >= 900 && submission < 1000) {
			counter[7] += 1;
		}
		else {
			counter[8] += 1;
		}
		submission = getSalary();
	}

	cout << "\n\nSalaries" << setw(20) << "Workers\n";
	cout << left << setw(23) << "$200-299" << counter[0] << endl;
	cout << left << setw(23) << "$300-399" << counter[1] << endl;
	cout << left << setw(23) << "$400-499" << counter[2] << endl;
	cout << left << setw(23) << "$500-599" << counter[3] << endl;
	cout << left << setw(23) << "$600-699" << counter[4] << endl;
	cout << left << setw(23) << "$700-799" << counter[5] << endl;
	cout << left << setw(23) << "$800-899" << counter[6] << endl;
	cout << left << setw(23) << "$900-999" << counter[7] << endl;
	cout << left << setw(23) << "$1000 and over" << counter[8] << endl;
	
	return 0;
}