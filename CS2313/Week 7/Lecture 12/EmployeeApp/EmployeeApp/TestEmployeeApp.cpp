
#include <iostream>
#include "Employee.h"

using namespace std;

int main() {
	Date birth1{ 12, 24, 1970 };
	Date birth2{ 10, 14, 1980 };
	Date hire1{ 1, 1, 2003 };
	Date hire2{ 7, 4, 2010 };

	Employee emp1{ "Joyce", "Blue", birth1, hire1 };
	Employee emp2{ "Mark", "White", birth2, hire2 };

	Employee::companyName = "Google Inc";
	cout << emp1.toString() << endl;
	cout << emp2.toString() << endl;

	return 0;
}