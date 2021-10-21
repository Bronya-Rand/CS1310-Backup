#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double amount, double interest) :BasePlusAccount(amount){
	interestRate = interest;
}

double SavingsAccount::calculateInterest() {
	return (getBalance() * interestRate);
}

SavingsAccount::~SavingsAccount() {

}