
#include <string>

//the guard include
#ifndef DATE_H
#define DATE_H

using namespace std;

class Date {
public:
	Date(unsigned int m, unsigned int d, unsigned int y); //constructor
	~Date(); //destructor
	string toString();
private:
	const static int numberOfMonths{ 12 };

	unsigned int checkDay(unsigned int testDay);
	unsigned int month{ 1 };
	unsigned int day{ 1 };
	unsigned int year{ 1900 };
};

#endif // DATE_H