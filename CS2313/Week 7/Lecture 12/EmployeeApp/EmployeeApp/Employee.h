
#include <string>
#include "Date.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
	Employee(const string& first, const string& last, const Date& dateOfBirth, const Date& dateOfHire);
	~Employee();
	string toString();
	static string companyName;
private:
	string firstName;
	string lastName;
	Date birthDate;
	Date hireDate;
};

#endif