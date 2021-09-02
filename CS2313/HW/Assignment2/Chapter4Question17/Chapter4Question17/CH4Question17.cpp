
#include <iostream>

using namespace std;

int main() {
	int counter{ 0 };
	int number{ 0 };
	int largest{ 0 };

	while (counter <= 9) {
		cout << "Enter a whole number: ";
		cin >> number;

		if (number >= largest) {
			largest = number;
		}
		counter++;
	}
	cout << "The largest number you inputted was: " << largest << endl;
	return 0;
}