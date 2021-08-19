
#include <iostream>
#include <string>

using namespace std;

string name;
double balance{ 0 };

void deposit(double amount) {
	balance += amount;
}

int main() {
	cout << "Enter the account name: ";
	//cin >> name;
	getline(cin, name);

	cout << "Enter the account balance: ";
	cin >> balance;
	
	double depositAmount{ 0 };
	cout << "Enter an amount to deposit: ";
	cin >> depositAmount;

	deposit(depositAmount);

	cout << "---------------------------------\n";
	cout << "Account Name: " << name << endl;
	cout << "Account Balance: " << balance << endl;

	return 0;
}