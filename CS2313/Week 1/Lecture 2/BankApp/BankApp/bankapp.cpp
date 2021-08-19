
#include <iostream>

#include "account.h"

using namespace std;

int main() {
	
	Account myAccount; //myAccount is an object/instance from the class Account
	myAccount.setBalance(100);
	myAccount.setName("Jacques Schnee");

	cout << "The balance of my account object is " << myAccount.getBalance() << endl;
	cout << "The name of my account object is " << myAccount.getName() << endl;
	

	cout << "----------------------------------------\n";
	Account myAccount2{ "Willow Schnee", 200.50 };
	
	double depositAmount;
	cout << "Please enter a amount to deposit: ";
	cin >> depositAmount;
	myAccount2.deposit(depositAmount);

	cout << "The balance of my second account object is " << myAccount2.getBalance() << endl;
	cout << "The name of my second account object is " << myAccount2.getName() << endl;

	return 0;
}