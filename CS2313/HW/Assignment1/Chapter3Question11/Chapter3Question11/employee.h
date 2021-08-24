/*
Chapter 3 Question 11 Header File
Author: Azariel Del Carmen
*/

#include <iostream>
#include <string>

using namespace std;

class Employee {
	string firstName;
	string lastName;
	int salary{};

public:

	Employee(string first, string last, int earnings) {
		firstName = first;
		lastName = last;
		if (earnings < 0){
			salary = 0;
		}
		else {
			salary = earnings;
		}
	}

	int giveRaise() {
		salary = salary * 1.10;
	}

	string getFirstName() {
		return firstName;
	}

	string getLastName() {
		return lastName;
	}

	int getSalary() {
		return salary;
	}

	void setFirstName(string first) {
		firstName = first;
	}

	void setLastName(string last) {
		lastName = last;
	}

	void setSalary(int earnings) {
		if (earnings < 0)
		{
			salary = 0;
		}
		else {
			salary = earnings;
		}
	}

};