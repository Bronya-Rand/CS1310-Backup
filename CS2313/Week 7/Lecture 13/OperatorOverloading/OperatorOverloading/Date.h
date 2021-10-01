#include<iostream>
#include <array>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date {
	friend void operator<<(ostream& out, Date& date);
public:
	void setDate(int mm, int dd, int yy);
	unsigned int getMonth();
	unsigned int getDay();
	unsigned int getYear();
	Date& operator++(); //pre-increment
	Date operator++(int); //post-increment
	Date& operator+=(unsigned int additionalDays);
private:
	int month;
	int day;
	int year;
	static array<unsigned int, 13> monthDays;
	void helpIncrement();
	bool endOfMonth(unsigned int testDay);
};

#endif
