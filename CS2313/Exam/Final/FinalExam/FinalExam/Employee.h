
#include "Person.h"

#ifndef EMP_H
#define EMP_H

class Employee :
    public Person
{
public:
    Employee();
    Employee(const std::string& ssn, const std::string& fn, const std::string& ln, const std::string& ad, const char& s, const double& sal, const int& dptNum);
    std::string getSSN();
    std::string getFirstName();
    std::string getLastName();
    std::string getAddress();
    char getSex();
    double getSalary();
    int getDptNum();
    std::string toString();
    bool operator==(const Employee& c);
private:
    double salary;
    int departmentNo;
    Person person;
};

#endif