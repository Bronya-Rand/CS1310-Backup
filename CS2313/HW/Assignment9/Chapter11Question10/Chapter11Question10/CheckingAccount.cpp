#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double balance, double fee) :BasePlusAccount(balance) {
    transactionFee = fee;
}

void CheckingAccount::credit(double add_amount) {
    BasePlusAccount::credit(add_amount - transactionFee);
    cout << "$" << getTransactionFee() << " transaction fee charged." << endl;
}

void CheckingAccount::debit(double withdraw_amount) {
    if (BasePlusAccount::debit(withdraw_amount) == true) {
        setBalance(getBalance() - transactionFee);
        cout << "$" << getTransactionFee() << " transaction fee charged." << endl;
    }
    else {
        throw invalid_argument("Debit amount exceeded account balance");
    }
}

double CheckingAccount::getTransactionFee() {
    return transactionFee;
}

CheckingAccount::~CheckingAccount() {

}