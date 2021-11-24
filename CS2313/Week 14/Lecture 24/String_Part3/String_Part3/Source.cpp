#include <iostream>
#include <string>
using namespace std;

int main() {
	string string1{ "The airplane landed on time. The service was great" };

	// retrieve substring "plane" which
	// begins at subscript 7 and consists of 5 characters
	cout << string1.substr(7, 5) << endl;
	cout << boolalpha << string1.empty() << endl;
	
	cout << string1.find("The") << endl;
	cout << string1.rfind("The") << endl;

	
	cout << "-----------------------------------\n";
	string first{ "one" };
	string second{ "two" };

	cout << "\n\nBefore swap:\n first: " << first << "\nsecond: " << second;

	first.swap(second); // swap strings

	cout << "\n\nAfter swap:\n first: " << first
		<< "\nsecond: " << second << endl;

	cout << "-----------------------------------\n";

	


}