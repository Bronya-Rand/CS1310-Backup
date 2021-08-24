/*
Chapter 3 Question 15
Author: Azariel Del Carmen
*/

#include <iostream>

#include ".\heartrates.h"

using namespace std;

int main() {
	string first;
	string last;
	int month{};
	int day{};
	int year{};
	int cYear{};

	cout << "What is your first name?: ";
	cin >> first;

	cout << "What is your last name?: ";
	cin >> last;

	cout << "What is the birth month?: ";
	cin >> month;

	cout << "What is the birth day?: ";
	cin >> day;

	cout << "What is the birth year?: ";
	cin >> year;

	cout << "What is the current year?: ";
	cin >> cYear;

	HeartRates you(first, last, month, day, year);
	HeartRates sg("Speedy", "Gonzales", 6, 24, 1979);

	cout << "Your first name is: " << you.getFirstName() << endl;
	cout << "Person 2's first name is: " << sg.getFirstName() << endl;

	cout << "\nSet Person 2's first name to Rapido\n";
	sg.setFirstName("Rapido");
	cout << "Person 2's first name is: " << sg.getFirstName() << endl << endl;

	cout << "Your last name is: " << you.getLastName() << endl;
	cout << "Person 2's last name is: " << sg.getLastName() << endl;

	cout << "\nSet Person 2's last name to Diaz\n";
	sg.setLastName("Diaz");
	cout << "Person 2's last name is: " << sg.getLastName() << endl << endl;

	cout << "Your birth month is: " << you.getMonth() << endl;
	cout << "Your birth day is: " << you.getDay() << endl;
	cout << "Your birth year is: " << you.getYear() << endl;

	cout << "\nSet person 2's month day and year to 6/21/2001.\n";
	sg.setMonth(6);
	sg.setDay(21);
	sg.setYear(2001);

	cout << "Person 2's birth month is: " << sg.getMonth() << endl;
	cout << "Person 2's birth day is: " << sg.getDay() << endl;
	cout << "Person 2's birth year is: " << sg.getYear() << endl << endl;

	cout << "Your age is: " << you.getAge(cYear) << endl;
	cout << "Person 2's age is: " << sg.getAge(cYear) << endl << endl;

	cout << "Your max heartrate is: " << you.getHeartRate(cYear) << endl;
	cout << "Person 2's max heartrate is: " << sg.getHeartRate(cYear) << endl << endl;

	cout << "Your target heartrate is: " << you.getTargetHeartRate(cYear) << endl;
	cout << "Person 2's target heartrate is: " << sg.getTargetHeartRate(cYear) << endl;

}