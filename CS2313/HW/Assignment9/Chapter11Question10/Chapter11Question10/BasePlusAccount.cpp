
#include "BasePlusAccount.h"

BasePlusAccount::BasePlusAccount(double dough) {
	setBalance(dough);
}

void BasePlusAccount::setBalance(double balance) {
	if (balance >= 0.0) {
		accountBalance = balance;
	}
	else {
		throw invalid_argument("Invalid initial balance. Initial balance must be greater than or equal to 0.");
	}
}

void BasePlusAccount::credit(double newDough) {
	accountBalance += newDough;
}

bool BasePlusAccount::debit(double neededDough) {
	if (neededDough <= accountBalance) {
		accountBalance -= neededDough;
		return true;
	}
	else {
		cout << "The amount you requested exceeds your current balance.\n";
		return false;
	}
}

double BasePlusAccount::getBalance() {
	return accountBalance;
}

BasePlusAccount::~BasePlusAccount() {

}