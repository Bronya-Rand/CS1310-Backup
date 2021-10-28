
#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h" 

using namespace std;

int main() {
    Account account1{ 50.0 };
    SavingsAccount account2{ 25.0, .03 };
    CheckingAccount account3{ 80.0, 1.0 };

    double deposit{};
    double withdraw{};

    //make vectors
    vector <Account*> accountVector;
    accountVector.push_back(&account1);
    accountVector.push_back(&account2); 
    accountVector.push_back(&account3); 

    for (int i = 0; i < int(accountVector.size()); i++) {
        cout << "How much would you like to deposit into your bank account?: ";
        cin >> deposit;
        cout << "How much would you like to withdraw from your bank accout?: ";
        cin >> withdraw;

        accountVector[i]->credit(deposit);
        accountVector[i]->debit(withdraw);

        if (accountVector[i] == accountVector[1]) { // 1 is savings with interest
            cout << "The total balance of your account plus interest is: $" << account2.calculateInterest() << endl;
            account2.setBalance(account2.calculateInterest() + account2.getBalance());
        }

        if (accountVector[i] == accountVector[0])
        {
            cout << "Account ";
        }
        else if (accountVector[i] == accountVector[1])
        {
            cout << "Savings Account ";
        }
        else
        {
            cout << "Checking Account ";
        }

        cout << "Balance: $" << accountVector[i]->getBalance() << endl << endl;
    }
}