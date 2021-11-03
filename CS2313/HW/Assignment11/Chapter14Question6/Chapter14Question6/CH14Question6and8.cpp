
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>

using namespace std;

int main() {
	int accountNum, accountNumber;
	string name;
	float currentBalance, dollarAmount;
	ifstream inOldMaster{ "oldmast.dat", ios::in };
	ifstream inTransaction{ "trans.dat", ios::in };
	ofstream outNewMaster{ "newmast.dat", ios::out };

	if (!inOldMaster) {
		cerr << "Cannot open file 'oldmast.dat'.";
		exit(EXIT_FAILURE);
	}
	if (!inTransaction) {
		cerr << "Cannot open file 'trans.dat'.";
		exit(EXIT_FAILURE);
	}
	if (!outNewMaster) {
		cerr << "Cannot write to file 'newmast.dat'.";
		exit(EXIT_FAILURE);
	}

	while (inOldMaster >> accountNumber >> quoted(name) >> currentBalance) {
		while (inTransaction >> accountNum >> dollarAmount) {
			if (accountNumber == accountNum) {
				currentBalance += dollarAmount;
			}
		}
		inTransaction.clear();
		inTransaction.seekg(0, ios::beg);

		outNewMaster << accountNumber << " " << quoted(name) << " " << currentBalance << endl;
	}

	while (inTransaction >> accountNum >> dollarAmount) {
		bool inMaster = false;
		inOldMaster.clear();
		inOldMaster.seekg(0, ios::beg);

		while (inOldMaster >> accountNumber >> quoted(name) >> currentBalance) {
			if (accountNum == accountNumber) {
				inMaster = true;
			}
		}
		if (!inMaster) {
			cout << "Unmatched transaction record for account number: " << accountNum << endl;
		}
	}
	return 0;
}