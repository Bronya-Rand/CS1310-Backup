
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	unsigned int frequency1{ 0 };
	unsigned int frequency2{ 0 };
	unsigned int frequency3{ 0 };
	unsigned int frequency4{ 0 };
	unsigned int frequency5{ 0 };
	unsigned int frequency6{ 0 };

	int face;

	unsigned int times = 1000;

	for (int i = 0; i < times; i++) {
		face = 1 + rand() % 6;
		
		switch (face) {
			case 1:
				frequency1++;
				break;
			case 2:
				frequency2++;
				break;
			case 3:
				frequency3++;
				break;
			case 4:
				frequency4++;
				break;
			case 5:
				frequency5++;
				break;
			case 6:
				frequency6++;
				break;
			default:
				break;
		}
	}

	cout << setw(10) << "Face" << setw(20) << "Frequency" << setw(12) << "Percentage" << endl;
	cout << setw(4) << endl;
	return 0;
}