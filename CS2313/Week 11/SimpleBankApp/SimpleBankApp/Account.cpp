#include "Account.h"
#include <iomanip>
#include <sstream>

Account::Account(int accNo, string na, double bal) :accountNo{ accNo }, name{ na }, balance{ bal } {

}
void Account::setAccountNum(int accNo) {
	accountNo = accNo;
}
void Account::setName(string na) {
	name = na;
}
void Account::setBalance(double bal) {
	balance = bal;
}
int Account::getAccountNum() {
	return accountNo;
}
string Account::getName() {
	return name;
}
double Account::getBalance() {
	return balance;
}
string Account::toString() {
	ostringstream output;
	output << left << setw(15) << accountNo << setw(15) << name << "$" << setw(15) << balance << endl;
	return output.str();
}
Account::~Account() {

}