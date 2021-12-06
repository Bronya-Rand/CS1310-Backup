#include <iostream>
#include <vector>
#include "Employee.h"
#include "Department.h"
#include <iomanip>
#include <fstream>

using namespace std;

vector<Employee*> employeeList;
vector<Department*> departmentList;

void readEmployeeData(string filePath);
void readDepartmentData(string filePath);
void displayEmployeeData();
void displayDepartmentData();
Employee* getEmployeeWithMaxSalary();
void searchBySalary();
double getDepartmentManagerSalary(int deptNumber);
double getTotalDepartmentSalaries(string deptName);
void releaseMemoryResources();

int main()
{
	readEmployeeData("EmployeesData.txt");
	displayEmployeeData();
	cout << endl << endl;

	cout << "Employee with Maximum Salary:\n";
	cout << getEmployeeWithMaxSalary()->toString() << endl;
	cout << endl << endl;

	cout << "Search By Salary:\n";
	//You MUST use the overloaded operator in the Employee class 
	searchBySalary();
	cout << endl << endl;
	readDepartmentData("DepartmentData.txt");
	displayDepartmentData();
	cout << endl << endl;

	cout << "Get Salary of Department's Manager:\n";
	int deptNumber;
	cout << "Enter department number: ";
	cin >> deptNumber;
	cout << "\nManager's salary of department " << deptNumber << " = "
		<< fixed << setprecision(2) << "$"
		<< getDepartmentManagerSalary(deptNumber);
	cout << endl << endl;

	cout << "Get Department Salaries:\n";
	string deptName;
	cout << "Enter department name: ";
	cin >> deptName;
	cout << "\nTotal salaries in department: " << deptName << " = "
		<< fixed << setprecision(2) << "$" << getTotalDepartmentSalaries(deptName)
		<< endl;

	releaseMemoryResources();
	cout << endl << endl;
	cout << "All memory resources have been released\n";
	return 0;
}

void displayEmployeeData()
{
	cout << "Employee Data: \n\n";
	cout << left << setw(13) << "SSN"
		<< setw(10) << "F_Name"
		<< setw(10) << "L_Name"
		<< setw(25) << "Address"
		<< setw(5) << "Sex"
		<< setw(10) << "Salary"
		<< setw(10) << "Dept. No" << endl;
	cout << "----------------------------------------------------------------\n";

	for (Employee* emp : employeeList)
		//for (size_t i{ 0 }; i < employeeList.size(); i++) 
	{
		cout << emp->toString() << endl;
		//cout << employeeList[i]->toString() << endl; 
	}

}

void displayDepartmentData()
{
	cout << "Department Data: \n\n";
	cout << left << setw(7) << "Dept#"
		<< setw(20) << "Dept. Name"
		<< setw(20) << "Mgr SSN" << endl;
	cout << "-------------------------------------\n";
	for (Department* dept : departmentList)
	{
		cout << dept->toString() << endl;
	}

}

void readEmployeeData(string filePath)
{
	string ssn, fn, ln, address;
	char s;
	double sal;
	int dptNum;

	ifstream inEmployeeData{ filePath, ios::in };

	if (!inEmployeeData) {
		cerr << "Cannot open file '" << filePath << "'.";
		exit(EXIT_FAILURE);
	}

	while (inEmployeeData >> ssn >> fn >> ln >> address >> s >> sal >> dptNum) {
		employeeList.push_back(new Employee(ssn, fn, ln, address, s, sal, dptNum));
	}
}

void readDepartmentData(string filePath)
{
	int num;
	string n;
	string ssn;

	ifstream inDepartmentData{ filePath, ios::in };

	if (!inDepartmentData) {
		cerr << "Cannot open file '" << filePath << "'.";
		exit(EXIT_FAILURE);
	}

	while (inDepartmentData >> num >> n >> ssn) {
		for (Employee* i : employeeList) {
			if (i->getSSN() == ssn) {
				departmentList.push_back(new Department(num, n, *i));
			}
		}
	}
}

Employee* getEmployeeWithMaxSalary()
{
	Employee* maxSalaryEmployee = employeeList[0];

	for (Employee* i : employeeList) {
		if (i->getSalary() > maxSalaryEmployee->getSalary()) {
			maxSalaryEmployee = i;
		}
	}

	return maxSalaryEmployee;
}

double getDepartmentManagerSalary(int deptNumber)
{
	for (Department* i : departmentList) {
		if (i->getNumber() == deptNumber) {
			return i->getManager().getSalary();
		}
	}
}

void searchBySalary()
{
	double findSalary{};
	cin >> findSalary;

	for (Employee* i : employeeList) {
		if (i->getSalary() == findSalary) {
			cout << i->toString() << endl;
		}
	}
}

double getTotalDepartmentSalaries(string deptName)
{
	int dptNum{0};
	double total{ 0.0 };

	for (Department* i : departmentList) {
		if (i->getName() == deptName) {
			dptNum = i->getNumber();
		}
	}

	for (Employee* i : employeeList) {
		if (i->getDptNum() == dptNum)
		{
			total = total + i->getSalary();
		}
	}

	return total;
}

void releaseMemoryResources()
{
	departmentList.clear();
	employeeList.clear();
}