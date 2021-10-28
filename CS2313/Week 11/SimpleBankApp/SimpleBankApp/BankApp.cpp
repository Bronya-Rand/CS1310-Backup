#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include "Account.h"

using namespace std;

vector<Account> accountsList; // the data structure to store all your accounts

int menu();
void readFile(string filePath);
void displayAllAccounts();
void displayAccountsWithZero();
void displayAccountsWithPos();
void displayAccountsWithNeg();
void addAccount();
void searchAccount();
int findAccountIndex(int accountNo);
void editAccount();
void deleteAccount();
void saveFile(string filePath);

int main() {
	int menuOption{ 0 };

	while ((menuOption = menu()) != 11) {
		switch (menuOption) {
		case 1:
			readFile("Clients.txt");
			break;
		case 2:
			displayAllAccounts();
			break;
		case 3:
			displayAccountsWithZero();
			break;
		case 4:
			displayAccountsWithPos();
			break;
		case 5:
			displayAccountsWithNeg();
			break;
		case 6:
			addAccount();
			break;
		case 7:
			searchAccount();
			break;
		case 8:
			editAccount();
			break;
		case 9:
			deleteAccount();
			break;
		case 10:
			saveFile("UpdatedClients.txt");
			break;
		default:
			cout << "Invalid option, please insert [1..11]\n";
			break;
		}
	}
}

int menu() {
	int option{};
	cout << endl;
	cout << "1 - Read Data From File\n";
	cout << "2 - Display All Accounts\n";
	cout << "3 - Display Accounts with ZERO balances\n";
	cout << "4 - Display Accounts with POSITIVE balances\n";
	cout << "5 - Display Accounts with NEGATIVE balances\n";
	cout << "6 - Add New Account\n";
	cout << "7 - Search Account\n";
	cout << "8 - Edit Account\n";
	cout << "9 - Delete Account\n";
	cout << "10 - Save File\n";
	cout << "11 - Exit\n";
	cout << "Choice> ";
	cin >> option;

	return option;
}

void readFile(string filePath) {
	ifstream inFile{ filePath, ios::in };
	if (!inFile) {
		cerr << "The file cannot be opened\n";
		exit(EXIT_FAILURE);
	}

	int accountNo;
	string name;
	double balance;

	while (inFile >> accountNo >> name >> balance) {
		Account acc{ accountNo, name, balance };
		accountsList.push_back(acc);
	}
	inFile.close();
	cout << "Data file has been loaded.\n";
}

void displayAllAccounts() {
	cout << left << setw(15) << "Account #" << setw(15) << "Name" << setw(15) << "Balance" << endl;
	cout << "-----------------------------------------------\n";
	for (Account& acc : accountsList) {
		cout << acc.toString();
	}
}

void displayAccountsWithZero() {
	for (Account& acc : accountsList) {
		if (acc.getBalance() == 0) {
			cout << acc.toString();
		}
	}
}

void saveFile(string filePath) {
	ofstream outFile{ filePath, ios::out };
	if (!outFile) {
		cerr << "The file cannot be opened\n";
		exit(EXIT_FAILURE);
	}

	for (Account& acc : accountsList) {
		outFile << acc.getAccountNum() << " " << acc.getName() << " " << acc.getBalance() << endl;
	}
	outFile.close();
	cout << "Data file has been saved.\n";
}

void displayAccountsWithPos() {
	for (Account& acc : accountsList) {
		if (acc.getBalance() > 0) {
			cout << acc.toString();
		}
	}
}
void displayAccountsWithNeg() {
	for (Account& acc : accountsList) {
		if (acc.getBalance() < 0) {
			cout << acc.toString();
		}
	}
}

void addAccount() {
	int accNo;
	string name;
	double bal;

	cout << "Account #? ";
	cin >> accNo;

	cout << "Name? ";
	cin >> name;

	cout << "Balance? ";
	cin >> bal;

	Account acc{ accNo, name, bal };
	accountsList.push_back(acc);
	cout << "\n1 Account has been added\n";
}

int findAccountIndex(int accountNo) {
	for (int i = 0; i < accountsList.size(); i++) {
		if (accountsList[i].getAccountNum() == accountNo) {
			return i;
		}
	}
	return -1;
}

void searchAccount() {
	int accNo;
	int accountIndex;
	cout << "Acc No? ";
	cin >> accNo;
	accountIndex = findAccountIndex(accNo);

	if (accountIndex != -1) {
		cout << accountsList[accountIndex].toString();
	}
	else {
		cout << "\nAccount not found.\n";
	}
}

void editAccount() {
	int accNo;
	int accountIndex;
	cout << "Acc No to edit? ";
	cin >> accNo;
	accountIndex = findAccountIndex(accNo);

	if (accountIndex != -1) {
		string newName;
		double newBalance;
		cout << accountsList[accountIndex].toString();
		cout << "New name? ";
		cin >> newName;
		cout << "New balance? ";
		cin >> newBalance;

		accountsList[accountIndex].setName(newName);
		accountsList[accountIndex].setBalance(newBalance);

		cout << "\n1 account has been edited.\n";
	}
	else {
		cout << "\nAccount not found.\n";
	}
}

void deleteAccount() {
	int accNo;
	int accountIndex;
	cout << "Acc No to delete? ";
	cin >> accNo;
	accountIndex = findAccountIndex(accNo);

	if (accountIndex != -1) {
		accountsList.erase(accountsList.begin() + accountIndex);
		cout << "\n1 account has been deleted.\n";
	}
	else {
		cout << "\nAccount not found.\n";
	}
}