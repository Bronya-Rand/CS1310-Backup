
#include "Employee.h"
#include <string>

#ifndef DPT_H
#define DPT_H

using namespace std;

class Department
{
public:
	Department();
	Department(const int& num, const std::string& n, const Employee& m);
	int getNumber();
	std::string getName();
	Employee getManager();
	std::string toString();
	~Department();
private:
	int number;
	std::string name;
	Employee manager;
};

#endif