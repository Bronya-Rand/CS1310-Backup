#include <string>

#ifndef PER_H
#define PER_H

class Person
{
public:
	Person();
	Person(const std::string& ssn, const std::string& fn, const std::string& ln, const std::string& ad, const char& s);
	std::string getSSN();
	std::string getFirstName();
	std::string getLastName();
	std::string getAddress();
	char getSex();
	virtual std::string toString();
private:
	std::string socialSecurityNumber;
	std::string firstName;
	std::string lastName;
	std::string address;
	char sex;
};

#endif