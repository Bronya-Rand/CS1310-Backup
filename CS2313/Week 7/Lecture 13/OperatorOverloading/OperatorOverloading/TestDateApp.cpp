
#include <iostream>
#include "Date.h"
#include <sstream>

using namespace std;

void displayDate(Date& date) {
	cout << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
}

void operator<<(ostream& out, Date& date) {
	//out << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
	out << date.month << "/" << date.day << "/" << date.year << endl;
}

int main() {
	
	Date myDate;
	myDate.setDate(5, 31, 2010);
	cout << "myDate = ";
	displayDate(myDate);

	Date d2 = ++myDate;
	cout << "d2 = ";
	displayDate(d2);
	cout << "myDate = ";
	displayDate(myDate);

	cout << "-----------------------\n";
	Date d3 = myDate++;
	cout << "d3 = ";
	displayDate(d3);
	cout << "myDate = ";
	displayDate(myDate);

	cout << "-----------------------\n";
	Date d4 = myDate++;
	cout << "d4 = ";
	displayDate(d4);
	cout << "myDate = ";
	displayDate(myDate);

	cout << "-----------------------\n";
	myDate += 31;
	cout << "myDate = ";
	displayDate(myDate);

	cout << "----- Overloading -----\n";
	d3 = myDate++;
	cout << "d3 = ";
	displayDate(d3);
	cout << "myDate = ";
	displayDate(myDate);
	return 0;
}