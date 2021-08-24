/*
Chapter 3 Question 12 Header File
Author: Azariel Del Carmen
*/

#include <iostream>

using namespace std;

class Date {
	int month{};
	int day{};
	int year{};

public:

	Date(int m, int d, int y) {
		if (m < 1 || m > 12) {
			month = 1;
		}
		else {
			month = m;
		}
		day = d;
		year = y;
	}

	void displayDate() {
		cout << month << "/" << day << "/" << year << endl;
	}

	int getMonth() {
		return month;
	}

	int getDay() {
		return day;
	}

	int getYear() {
		return year;
	}

	void setMonth(int m) {
		if (m < 1 || m > 12) {
			month = 1;
		}
		else {
			month = m;
		}
	}

	void setDay(int d) {
		day = d;
	}

	void setYear(int y) {
		year = y;
	}

};