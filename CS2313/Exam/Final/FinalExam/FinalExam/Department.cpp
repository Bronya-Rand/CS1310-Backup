#include "Department.h"
#include <sstream>
#include <iomanip>

Department::Department() {

}

Department::Department(const int& num, const std::string& n, const Employee& m) {
	number = num;
	name = n;
	manager = m;
}

int Department::getNumber() {
	return number;
}

std::string Department::getName() {
	return name;
}

Employee Department::getManager() {
	return manager;
}

std::string Department::toString() {
	ostringstream out;
	out << std::left << std::setw(7) << getNumber() << std::setw(15) << getName() << std::setw(30) << getManager().getSSN() << endl;
	return out.str();
}

Department::~Department() {

}