
#include <iostream>

using namespace std;

int main() {
	int counter{ 1 };
	/*while (counter <= 10) {
		cout << counter << " ";
		counter++;
	}
	cout << endl;*/

	/*do {
		cout << counter << " ";
		counter++;
	} while (counter <= 10);*/

	for (int counter{ 1 }; counter <= 10, counter++) {
		cout << counter << " ";
	}
	cout << endl;

	return 0;
}