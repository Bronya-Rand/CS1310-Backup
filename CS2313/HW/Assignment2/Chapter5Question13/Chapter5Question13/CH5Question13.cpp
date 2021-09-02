
#include <iostream>

using namespace std;

int main() {

	int n{ 1 };
	long int value{ 1 };

	while (n <= 20) {
		value = value * n;
		cout << "1/" << n << "!: " << value << endl;
		n++;
	}

	return 0;
}