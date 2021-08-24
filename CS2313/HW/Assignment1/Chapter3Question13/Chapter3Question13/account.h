
#include <iostream>
#include <string>

using namespace std;

class Account {
	string name;
	int balance{};

public:

	Account(string first, int total) {
		name = first;
		if (total < 0) {
			balance = 0;
		}
		else {
			balance = total;
		}
	}

	int getBalance() {
		return balance;
	}

	string getName() { 
		return name;
	}

	void deposit(int depositAmount) {
		if (depositAmount > 0) {
			balance += depositAmount;
		}
		else {
			balance += 0;
		}
	}

};