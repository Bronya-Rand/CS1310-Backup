
#include <iostream>
#include <fstream> // deals with files
#include <cstdlib> // for exit function
#include <string>

using namespace std;

int main() {
	ofstream outFile("Clients.txt", ios::out);

	if (!outFile) {
		cerr << "File could not be created.\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter the account number, name and balance\n"
		<< "Enter end-of-file (CTRL+Z) to end the input\n?";

	int accountNumber{};
	string name;
	double balance;

	while (cin >> accountNumber >> name >> balance) {
		outFile << accountNumber << " " << name << " " << balance << endl;
		cout << "?";
	}
	outFile.close(); 
}