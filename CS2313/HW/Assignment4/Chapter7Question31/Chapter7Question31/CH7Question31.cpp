
#include <iostream>
#include <string>

using namespace std;

string reverseString(string r, int len) {
	if (len < 0) {
		return "\n";
	}

	cout << r[len];

	return reverseString(r, --len);
}

int main() {

	string revWord;

	cout << "Type in a string to read backwards: ";
	cin >> revWord;

	cout << endl << revWord << " backwards is: ";
	cout << reverseString(revWord, revWord.length() - 1);

	return 0;
}