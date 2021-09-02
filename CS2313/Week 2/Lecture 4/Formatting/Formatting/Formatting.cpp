
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string s1 = "aaaaaa"; // 6 chars
	string s2 = "bbb"; // 3 chars
	string s3 = "cccc"; // 4 chars
	string s4 = "xxxx"; // 4 chars

	cout << left << setw(20) << s1 << s4 << endl;
	cout << left << setw(20) << s2 << s4 << endl;
	cout << left << setw(20) << s3 << s4 << endl;

	return 0;
}