
#include "Employee.h"
#include <sstream>

Employee::Employee(const string& first, const string& last, const Date& dateOfBirth, const Date& dateOfHire) 
	:firstName{ first }, lastName{ last }, birthDate{ dateOfBirth }, hireDate{ dateOfHire } {

}

string Employee::toString() {
	ostringstream out;
	out << firstName << ", " << lastName << " Hired: " << hireDate.toString() << " Birthday: " << birthDate.toString() << endl;
	return out.str();
}

Employee::~Employee() {

}