/*
Chapter 3 Question 13
Author: Azariel Del Carmen
*/

#include <iostream>

#include ".\account.h"

using namespace std;

void displayAccount(Account accountToDisplay) {
	cout << accountToDisplay.getName() << " balance is $" << accountToDisplay.getBalance() << endl;
}

int main() {
	int depositAmount{};

	Account account1("Jane Green", 50);
	Account account2("John Blue", 0);

	displayAccount(account1);
	displayAccount(account2);

	cout << "\n\nEnter deposit amount to account1: ";
	cin >> depositAmount;
	cout << "adding " << depositAmount << " to account1's balance\n\n";
	account1.deposit(depositAmount);

	displayAccount(account1);
	displayAccount(account2);

	cout << "\n\nEnter deposit amount to account2: ";
	cin >> depositAmount;
	cout << "adding " << depositAmount << " to account2's balance\n\n";
	account2.deposit(depositAmount);

	displayAccount(account1);
	displayAccount(account2);;
}