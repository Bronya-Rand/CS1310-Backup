
#include <iostream>
#include <stdexcept>

using namespace std;

void freeMoney(int balance, int amount);
void letsExcept(int bal, int amount);
void letsControlExcept(int bal, int amount);

int main() {
	int bal{ 100 };

	freeMoney(bal, 865);
	cout << "---" << endl;
	letsControlExcept(bal, -210);
	letsControlExcept(bal, -500);
	letsExcept(bal, -210);
	cout << "You: Done." << endl;

}

void freeMoney(int balance, int amount) {
	if (amount <= 0) {
		throw invalid_argument("Program: You can get no or negative free numbers dummy!");
	}

	balance += amount;
	cout << "You: FREE MONEY!!! - $" << balance << endl;
}

void letsControlExcept(int bal, int amount) {
	cout << endl << "Executing Program Control Except" << endl << endl;
	try {
		freeMoney(bal, amount);
	}
	catch (logic_error& e) {
		cout << e.what() << endl;
		cout << "Barsoum: Yes! Teacher happy." << endl;
		//throw logic_error("Repeat!"); ERROR: causes program to terminate
	}
}

void letsExcept(int bal, int amount) {
	cout << endl << "Executing Pure Except" << endl << endl;
	cout << "Barsoum: NO! NOT THIS!!" << endl;
	freeMoney(bal, amount);
}