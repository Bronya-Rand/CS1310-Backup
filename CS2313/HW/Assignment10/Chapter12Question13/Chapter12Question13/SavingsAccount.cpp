
#include <stdexcept>
#include "SavingsAccount.h" 

using namespace std;

SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance), interestRate(0.0) {
    if (rate >= 0.0) {
        interestRate = rate;
    }
    else {
        throw invalid_argument("Interest rate must be >= 0.0");
    }
}

double SavingsAccount::calculateInterest() {
    return getBalance() * interestRate;
}