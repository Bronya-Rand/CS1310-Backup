#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <iostream>
#include <stdexcept>

using namespace std;

class BasePlusAccount {
public:
	BasePlusAccount();
	BasePlusAccount(double dough);
	void setBalance(double dough);
	void credit(double newDough);
	bool debit(double neededDough);
	double getBalance();
	~BasePlusAccount();
protected:
	double accountBalance;
};
#endif