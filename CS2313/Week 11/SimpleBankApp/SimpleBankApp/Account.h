#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
public:
	Account(int accNo, string na, double bal);
	void setAccountNum(int accNo);
	void setName(string na);
	void setBalance(double bal);
	int getAccountNum();
	string getName();
	double getBalance();
	string toString();
	~Account();
private:
	int accountNo;
	string name;
	double balance;
};

#endif