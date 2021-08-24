/*
Chapter 3 Question 15 Header File
Author: Azariel Del Carmen
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class HeartRates {
	string firstName;
	string lastName;
	int month{};
	int day{};
	int year{};

public:

	HeartRates(string first, string last, int m, int d, int y) {
		firstName = first;
		lastName = last;
		month = m;
		day = d;
		year = y;
	}

	int getAge(int cYear) {
		return cYear - year;
	}

	int getHeartRate(int cYear) {
		int age{};
		age = getAge(cYear);

		return 220 - age;

	}

	int getTargetHeartRate(int cYear) {
		int heartRate{};
		heartRate = getHeartRate(cYear);

		// average of the percentages
		return heartRate * ((1.50 + 1.85) / 2);

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

	string getFirstName() {
		return firstName;
	}

	string getLastName() {
		return lastName;
	}

	void setFirstName(string first) {
		firstName = first;
	}

	void setLastName(string last) {
		lastName = last;
	}

	void setMonth(int m) {
		month = m;
	}

	void setDay(int d) {
		day = d;
	}

	void setYear(int y) {
		year = y;
	}

};