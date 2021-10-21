
#include "BasePlusAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

int main() {
	BasePlusAccount acc1(50.0);
	CheckingAccount che1(75.0, 1.0);
	SavingsAccount sav1(100.0, 0.3);

	cout << "acc1 bal: $" << acc1.getBalance() << endl;
	cout << "che1 bal: $" << che1.getBalance() << endl;
	cout << "sav1 bal: $" << sav1.getBalance() << endl << endl;

	cout << "Debbiting to all accounts.\n";
	acc1.debit(25.0);
	che1.debit(30.0);
	sav1.debit(40.0);

	cout << "acc1 bal: $" << acc1.getBalance() << endl;
	cout << "che1 bal: $" << che1.getBalance() << endl;
	cout << "sav1 bal: $" << sav1.getBalance() << endl << endl;

	cout << "Crediting to all accounts.\n";
	acc1.credit(40.0);
	che1.credit(65.0);
	sav1.credit(20.0);

	cout << "acc1 bal: $" << acc1.getBalance() << endl;
	cout << "che1 bal: $" << che1.getBalance() << endl;
	cout << "sav1 bal: $" << sav1.getBalance() << endl << endl;

	sav1.credit(sav1.calculateInterest());
	cout << "Adding interest of 0.3% rate to sav1 is: $" << sav1.getBalance() << endl << endl;

}