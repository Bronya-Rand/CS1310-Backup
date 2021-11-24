
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string S, int first, int last) {
	if (first >= last) {
		return true;
	}

	if (S[first] != S[last]) {
		return false;
	}

	return isPalindrome(S, ++first, --last);
}

int allPalindromes(string S) {
	string word = "";
	int count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != ' ') {
			word = word + S[i];
		}
		else {
			cout << word << endl;
			if (isPalindrome(word, 0, word.length() - 1)) {
				count++;
			}
			word = "";
		}
	}
	return count;
}

int main() {

	string palindromeWord;

	cout << "Please type in a string to check: ";
	getline(cin, palindromeWord);
	while (palindromeWord != "exit") {
		cout << "We found " << allPalindromes(palindromeWord + ' ') << " palindromes in the string '" << palindromeWord << "'." << endl;

		cout << "Please type in a string to check: ";
		getline(cin, palindromeWord);
	}
	cout << "Exiting program..." << endl;

	return 0;
}