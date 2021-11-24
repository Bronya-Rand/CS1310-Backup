
#include <iostream>
#include <string>

using namespace std;

string backwards(string phrase) {
	for (int i = 0; i < phrase.size(); i++) {
		if (isupper(phrase[i]) && phrase[i] != ' ') {
			phrase[i] = tolower(phrase[i]);
		}
		else if (phrase[i] != ' ') {
			phrase[i] = toupper(phrase[i]);
		}
	}
	string reversed = phrase;

	for (int i = 0; i < phrase.size(); i++) {
		reversed[i] = phrase[(phrase.size() - 1) - i];
	}
	return reversed;
}

int main() {
	string phrase;

	cout << "Please provide a string to read backwards: ";
	getline(cin, phrase);

	cout << phrase << " backwards is: " << backwards(phrase) << "." << endl;
	return 0;
}