#include "Person.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

Person::Person() {

}

Person::Person(const std::string& ssn, const std::string& fn, const std::string& ln, const std::string& ad, const char& s) {
	if (ssn.length() == 9) {
		socialSecurityNumber = ssn;
	}
	else {
		cerr << "SSN is not 9 characters.";
		exit(EXIT_FAILURE);
	}
	firstName = fn;
	lastName = ln;
	address = ad;
	sex = s;
}

string Person::getSSN() {
	return socialSecurityNumber;
}

string Person::getFirstName() {
	return firstName;
}

string Person::getLastName() {
	return lastName;
}

string Person::getAddress() {
	return address;
}

char Person::getSex() {
	return sex;
}

std::string Person::toString() {
	std::ostringstream out;
	out << "First Name: " << getFirstName() << endl;
	out << "Last Name: " << getLastName() << endl;
	out << "SSN: " << getSSN() << endl;
	out << "Address: " << getAddress() << endl;
	if (getSex() == 'm') {
		out << "Sex: Male\n";
	}
	else {
		out << "Sex: Female\n";
	}
	return out.str();
}