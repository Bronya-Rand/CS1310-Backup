
#ifndef CHECK_H
#define CHECK_H

#include "BasePlusAccount.h"
class CheckingAccount :
    public BasePlusAccount
{
public:
    CheckingAccount();
    CheckingAccount(double amount, double fee);
    double getTransactionFee();
    void credit(double amount);
    void debit(double amount);
    ~CheckingAccount();
protected:
    double transactionFee;
};
#endif

