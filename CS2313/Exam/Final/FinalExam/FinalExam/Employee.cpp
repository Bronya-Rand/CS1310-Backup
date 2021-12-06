#include "Employee.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Employee::Employee() {

}

Employee::Employee(const std::string& ssn, const std::string& fn, const std::string& ln, const std::string& ad, const char& s, const double& sal, const int& dptNum) : person(ssn, fn, ln, ad, s) {
	salary = sal;
	departmentNo = dptNum;
}

std::string Employee::getSSN() {
	return person.getSSN();
}

std::string Employee::getFirstName() {
	return person.getFirstName();
}

std::string Employee::getLastName() {
	return person.getLastName();
}

std::string Employee::getAddress() {
	return person.getAddress();
}

char Employee::getSex() {
	return person.getSex();
}

double Employee::getSalary() {
	return salary;
}

int Employee::getDptNum() {
	return departmentNo;
}

std::string Employee::toString() {
	std::ostringstream out;
	out << std::left << std::setw(13) << person.getSSN() << std::setw(10) << person.getFirstName() << std::setw(10) << person.getLastName() << std::setw(25) << person.getAddress() << std::setw(5) << person.getSex() << std::setw(10) << getSalary() << std::setw(10) << getDptNum();
	return out.str();
}

bool Employee::operator==(const Employee& c) {
	Employee temp{ *this };
	return (temp.salary == c.salary);
}