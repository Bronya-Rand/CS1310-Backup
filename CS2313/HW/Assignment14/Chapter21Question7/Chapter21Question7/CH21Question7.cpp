
#include <iostream>
#include <string>

using namespace std;

string encrypt(string x) {
	for (int i = 0; i < x.size(); i++) {
		if (((int) x[i] + 13) > 122 && x[i] != ' ') {
			x[i] = (char) (((int) x[i] + 13) - 26);
		}
		else if (x[i] != ' ') {
			x[i] = (char) ((int) x[i] + 13);
		}
	}
	return x;
}

string decrypt(string x) {
	int i = 0;

	for (int i = 0; i < x.size(); i++) {
		if (((int) x[i] - 13) < 97 && x[i] != ' ') {
			x[i] = (char) (((int) x[i] - 13) + 26);
		}
		else if (x[i] != ' ') {
			x[i] = (char) ((int) x[i] - 13);
		}
	}
	return x;
}

int main() {
	string phrase;
	int input;

	cout << "Do you want to encrypt (1) or decrypt (2) a string?: ";
	cin >> input;

	while (!cin.eof()) {
		switch (input) {
		case 1:
			cin.ignore();
			cout << "Enter the string to encrypt: ";
			getline(cin, phrase);
			cout << "\nFinished! Your encrypted text is: " << encrypt(phrase) << endl;
			break;
		case 2:
			cin.ignore();
			cout << "Enter the string to decrypt: ";
			getline(cin, phrase);
			cout << "\nFinished! Your decrypted text is: " << decrypt(phrase) << endl;
			break;
		default:
			cout << "Invalid input. Please try again.\n\n";
			break;
		}

		cout << "Do you want to encrypt (1) or decrypt (2) a string?: ";
		cin >> input;
	}
	cout << "Exiting program..." << endl;
	return 0;
}