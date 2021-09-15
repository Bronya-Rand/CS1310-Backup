
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

int main() {

	string palindromeWord;

	cout << "Please type in a string to check: ";
	cin >> palindromeWord;

	if (isPalindrome(palindromeWord, 0, palindromeWord.length() - 1)) {
		cout << endl << palindromeWord << " is a palindrome.\n\n";
	}
	else {
		cout << endl << palindromeWord << " is not a palindrome.\n\n";
	}

	return 0;
}