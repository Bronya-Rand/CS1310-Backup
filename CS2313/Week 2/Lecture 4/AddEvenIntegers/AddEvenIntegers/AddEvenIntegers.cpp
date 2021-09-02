
#include <iostream>

using namespace std;

int main() {
	int total{ 0 };

	for (unsigned int i = 0; i <= 20; i += 2) {
		total += i;
	}
	cout << total << endl;

	return 0;
}