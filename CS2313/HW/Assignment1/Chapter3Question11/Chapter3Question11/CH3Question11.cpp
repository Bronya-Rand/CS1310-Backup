
#include <iostream>

#include ".\employee.h"

using namespace std;

int main()
{
	string first;
	string last;
	int earnings{};

	cout << "What is your first name?: ";
	cin >> first;

	cout << "What is your last name?: ";
	cin >> last;

	cout << "How much is your salary? (whole numbers only): ";
	cin >> earnings;

	Employee man(first, last, earnings);
	Employee rwby("Neo", "Politan", 120000);
	cout << "Your salary is: $" << man.getSalary() << endl;

	cout << "\nSet salary to -20000\n";
	man.setSalary(-20000);
	cout << "Your salary is: $" << man.getSalary() << endl << endl;

	cout << "Your first name is: " << man.getFirstName() << endl;

	cout << "\nSet first name to Ruby\n";
	man.setFirstName("Ruby");
	cout << "Your first name is: " << man.getFirstName() << endl << endl;

	cout << "Your last name is: " << man.getLastName() << endl;

	cout << "\nSet last name to Rose\n";
	man.setLastName("Rose");
	cout << "Your last name is: " << man.getLastName() << endl << endl;

	cout << "Employee 2's first name is: " << rwby.getFirstName() << endl;
	cout << "Employee 2's last name is: " << rwby.getLastName() << endl;
	cout << "Employee 2's salary is: " << rwby.getSalary() << endl;
	cout << "\n\n*Neo smirks evilly.*\n";
	rwby.setSalary(2000000);
	cout << "Employee 2's salary is: " << rwby.getSalary() << endl;
	
}