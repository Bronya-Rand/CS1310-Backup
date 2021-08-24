
#include <iostream>

using namespace std;

int main()
{
	int x{};

	cout << "Please type in a whole number: ";
	cin >> x;

	if (x % 2 == 0) {
		cout << x << " is a even number.\n";
	}
	else {
		cout << x << " is a odd number.\n";
	}
}