
#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

int main() {

	vector<int> uniqueVector{ 20 };
	int count{ 1 };
	int value{};

	srand(static_cast<unsigned int>(time(NULL)));

	while (count <= 20) {
		bool unique = true;
		value = rand() % 91 + 10;

		for (int i : uniqueVector) {
			if (value == i) {
				unique = false;
			}
		}

		if (unique == true) {
			uniqueVector.push_back(value);
			count++;
		}
	}

	cout << "Your unique numbers are\n";
	cout << "-------------------------------------------------------------\n";
	for (int i : uniqueVector) {
		cout << i << " ";
	}

	cout << endl;
	return 0;
}
