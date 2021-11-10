
#include <iostream>
#include <stdexcept>

using namespace std;

void freeMoney(int balance, int amount);
void hackerMode(int victimBalance, int steal);

int main() {
	int bal{ 100 };

	freeMoney(bal, 865); 
	cout << "---" << endl;
	cout << "Hacker: NOW YOU LOSE MONEY!" << endl;
	//throw; //improper just throw
	try {
		hackerMode(bal, 100000);
	}
	catch (logic_error& e) {
		cout << e.what() << endl;
		cout << "You: Nice try." << endl;
		cout << "Hacker: NOOO! *ded*" << endl;
	}
	//throw invalid_argument("FBI: This money is dirty."); //improper way but works
}

void hackerMode(int victimBalance, int steal) {
	try {
		cout << "Hacker: AHAHAHA" << endl;
		freeMoney(victimBalance, -steal);
		cout << "You: NOOO!" << endl;
		cout << "You: Barsoum... why did you not make this program secure... Me not happy." << endl;
	}
	catch (logic_error& e) {
		throw;
	}
}

void freeMoney(int balance, int amount) {
	if (amount <= 0) {
		throw invalid_argument("Program: You can get no or negative free numbers dummy!");
	}

	balance += amount;
	cout << "You: FREE MONEY!!! - $" << balance << endl;
}