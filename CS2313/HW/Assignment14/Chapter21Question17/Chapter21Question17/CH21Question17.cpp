
#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
	string phrase;

	cout << "Please type in a string to check: ";
	getline(cin, phrase);
	while (phrase != "exit") {
		array<int, 5> vowelCount{ 0, 0, 0, 0, 0 }; // a, e, i, o, u
		for (int x = 0; x < phrase.size(); x++) {
			if (phrase[x] == 'a') {
				vowelCount[0]++;
			}
			else if (phrase[x] == 'e') {
				vowelCount[1]++;
			}
			else if (phrase[x] == 'i') {
				vowelCount[2]++;
			}
			else if (phrase[x] == 'o') {
				vowelCount[3]++;
			}
			else if (phrase[x] == 'u') {
				vowelCount[4]++;
			}
		}

		int total = 0;
		for (int i = 0; i < 5; i++) {
			total += vowelCount[i];
		}

		cout << "Your string of '" << phrase << "' had " << total << " vowels in total.\nThese are the following vowel frequencies for your string: \n";
		cout << "A: " << vowelCount[0] << endl;
		cout << "E: " << vowelCount[1] << endl;
		cout << "I: " << vowelCount[2] << endl;
		cout << "O: " << vowelCount[3] << endl;
		cout << "U: " << vowelCount[4] << endl << endl;

		cout << "Please type in a string to check: ";
		getline(cin, phrase);
	}
	cout << "Exiting program..." << endl;

	return 0;
}