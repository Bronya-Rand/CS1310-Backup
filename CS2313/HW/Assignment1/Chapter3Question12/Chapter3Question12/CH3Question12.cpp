/*
Chapter 3 Question 12
Author: Azariel Del Carmen
*/

#include <iostream>

#include ".\date.h"

using namespace std;

int main()
{
	int month{};
	int day{};
	int year{};

	cout << "What is the month?: ";
	cin >> month;

	cout << "What is the day?: ";
	cin >> day;

	cout << "What is the year?: ";
	cin >> year;

	Date rz(month, day, year);
	rz.displayDate();
	cout << "The month is: " << rz.getMonth() << endl;
	cout << "The day is: " << rz.getDay() << endl;
	cout << "The year is: " << rz.getYear() << endl;

	cout << "\nSet month day and year to -1/31/1969.\n";
	rz.setMonth(-1);
	rz.setDay(31);
	rz.setYear(1969);
	rz.displayDate();
	cout << "The month is: " << rz.getMonth() << endl;
	cout << "The day is: " << rz.getDay() << endl;
	cout << "The year is: " << rz.getYear() << endl;
}