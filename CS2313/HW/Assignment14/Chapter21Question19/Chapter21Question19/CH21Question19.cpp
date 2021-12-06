
#include <iostream>
#include <string>

using namespace std;

int main() {
	string phrase;
	string lowerBy = "by";
	string upperBy = "BY";

	cout << "Please type in a string to remove 'by' or 'BY' from: ";
	getline(cin, phrase);
	while (phrase != "exit") {
		size_t lowerPos = phrase.find(lowerBy);
		while (lowerPos != string::npos)
		{
			phrase.erase(lowerPos, 2);
			lowerPos = phrase.find(lowerBy, lowerPos);
		}
		size_t upperPos = phrase.find(upperBy);
		while (upperPos != string::npos)
		{
			phrase.erase(upperPos, 2);
			upperPos = phrase.find(upperBy, upperPos);
		}
		cout << "Removing by and BY returned the following string: " << phrase << endl;

		cout << "Please type in a string to remove 'by' or 'BY' from: ";
		getline(cin, phrase);
	}
	cout << "Exiting program..." << endl;

	return 0;
}