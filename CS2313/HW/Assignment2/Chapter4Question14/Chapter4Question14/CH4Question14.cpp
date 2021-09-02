
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int accountNumber{ 0 };
	double balance{ 0.00 };
	double charges{ 0.00 };
	double credits{ 0.00 };
	double creditLimit{ 0.00 };

	while (accountNumber != -1) {
		cout << fixed << setprecision(2);

		cout << "Enter account number (or -1 to quit): ";
		cin >> accountNumber;

		if (accountNumber != -1) {

			cout << "Enter beginning balance: ";
			cin >> balance;

			cout << "Enter total charges: ";
			cin >> charges;

			cout << "Enter total credits: ";
			cin >> credits;

			cout << "Enter credit limit: ";
			cin >> creditLimit;

			balance = balance + charges - credits;
			cout << "New Balance is " << balance << endl;

			if (balance > creditLimit) {
				cout << "Account: " << accountNumber << endl;
				cout << "Credit Limit: " << creditLimit << endl;
				cout << "Balance: " << balance << endl;
				cout << "Credit Limit Exceeded.\n";
			}
			cout << endl;
		}
	}
	return 0;
}