#include <iostream>
#include <string>

using namespace std;

class Account {
	string name;
	double balance{ 0 };

public:
	
	//Default Constructor
	Account() {

	}

	//Full Constructor
	/*Account(string accountName, double accountBalance) {
		if (accountBalance >= 0) {
			balance = accountBalance;
			name = accountName;
		}
		else {
			cout << "ERROR: The balance value must be >= $0 \n";
		}
	}*/

	Account(string accountName, double accountBalance) :name{ accountName } 
	{
		if (accountBalance >= 0) {
			balance = accountBalance;
			name = accountName;
		}
		else {
			cout << "ERROR: The balance value must be >= $0 \n";
		}
	}

	void setBalance(double accountBalance) {
		if (accountBalance >= 0) {
			balance = accountBalance;
		}
		else {
			cout << "ERROR: The balance value must be >= $0 \n";
		}
	}

	double getBalance() {
		return balance;
	}

	void setName(string accountName) {
		name = accountName;
	}

	string getName() const { //const means the function should not change my object
		return name;
	}

	void deposit(double depositAmount) {
		if (depositAmount > 0) {
			balance += depositAmount;
		}
		else {
			cout << "ERROR: The deposit amount value must be > $0 \n";
		}
	}
}; //the end of my class
