
#include "Date.h"

void Date::setDate(int mm, int dd, int yy) {
	// for simplicity, no validation
	month = mm;
	day = dd;
	year = yy;
}

unsigned int Date::getMonth() {
	return month;
}
unsigned int Date::getDay() {
	return day;
}
unsigned int Date::getYear() {
	return year;
}

void Date::helpIncrement() {
	if (!endOfMonth(day)) {
		day++;
	}
	else {
		if (month == 12) {
			year++;
			month = 1;
			day = 1;
		}
		else {
			month++;
			day = 1;
		}
	}
}

array<unsigned int, 13> Date::monthDays{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool Date::endOfMonth(unsigned int testDay) {
	if (year % 4 == 0 && month == 2) {
		return (testDay == 29);
	}
	else {
		return (testDay == monthDays[month]);
	}
}

Date& Date::operator++() {
	helpIncrement();
	return (*this);
}

Date Date::operator++(int) {
	Date temp{ *this };
	helpIncrement();
	return temp;
}

Date& Date::operator+=(unsigned int additionalDays) {
	for (int i = 0; i < additionalDays; i++) {
		helpIncrement();
	}
	return (*this);
}