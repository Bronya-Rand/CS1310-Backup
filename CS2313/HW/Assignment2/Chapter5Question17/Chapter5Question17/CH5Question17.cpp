
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	cout << fixed << setprecision(2);

	int productNumber{ 0 };
	double value{ 0.0 };

	while (productNumber != -1) {
		cout << "Type in a product number from 1-5. (-1 to exit): ";
		cin >> productNumber;

		switch (productNumber)
		{
			case -1:
				cout << "Finalizing total.\n\n";
				break;
			case 1:
				value += 2.98;
				break;
			case 2:
				value += 4.50;
				break;
			case 3:
				value += 9.98;
				break;
			case 4:
				value += 4.49;
				break;
			case 5:
				value += 6.87;
				break;
			default:
				cout << "Invalid input. Valid inputs are (1, 2, 3, 4, 5).\n\n";
				break;
		}
	}

	cout << "The total for all your items is: $" << value << endl;
	return 0;
}