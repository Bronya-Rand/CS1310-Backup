
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << "Output of the function rand() without srand initialization \n\n";

	for (unsigned int counter{ 1 }; counter <= 10; counter++) {
		cout << setw(20) << rand() << " ";
		if (counter == 5) {
			cout << endl;
		}
	}
	cout << endl;
	cout << "----------------------------------\n";

	int seed;
	cout << "Enter a seed value: ";
	cin >> seed;
	srand(seed);

	cout << "Output of the function rand() with srand initialization \n\n";

	for (unsigned int counter{ 1 }; counter <= 10; counter++) {
		cout << setw(20) << rand() << " ";
		if (counter == 5) {
			cout << endl;
		}
	}
}