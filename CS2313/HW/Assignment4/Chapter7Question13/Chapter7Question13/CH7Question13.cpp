
#include <iostream>
#include <random>
#include <array>
#include <ctime>

using namespace std;

int main() {

	const size_t arraySize{ 20 };
	array<int, arraySize> uniqueArray{};
	int count{ 1 };
	int value{};

	// read that sRand is 4 bits while time_t is 8 bits
	// to avoid C4244, I made it static cast to a unsigned int.
	srand(static_cast<unsigned int>(time(NULL)));

	while (count <= 20) {
		bool unique = true;
		value = rand() % 91 + 10;

		for (int i : uniqueArray) {
			if (value == i) {
				unique = false;
			}
		}

		if (unique == true) {
			uniqueArray[count - 1] = value;
			count++;
		}
	}

	cout << "Your unique numbers are\n";
	cout << "-------------------------------------------------------------\n";
	for (int i : uniqueArray) {
		cout << i << " ";
	}

	cout << endl;
	return 0;
}