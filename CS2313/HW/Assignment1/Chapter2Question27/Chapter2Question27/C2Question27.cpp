
#include <iostream>

using namespace std;

int main()
{
	char input{};

	cout << "Please provide a single letter, number or symbol: ";
	cin >> input;

	cout << input << " is the equivalent to " << static_cast<int>(input) << " in integer form.\n";
}