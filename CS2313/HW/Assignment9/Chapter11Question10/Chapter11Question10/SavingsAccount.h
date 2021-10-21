#ifndef SAV_H
#define SAV_H

#include "BasePlusAccount.h"
class SavingsAccount :
    public BasePlusAccount
{
public:
    SavingsAccount();
    SavingsAccount(double amount, double interest);
    double calculateInterest();
    ~SavingsAccount();
protected:
    double interestRate;
};
#endif
