
#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

const int rows{ 4 };
const int columns{ 5 };

void getProductCost(array<array<int, columns>, rows>& sales, int row);

int getID() {
	int saleID{};
	cout << "Please enter your saleperson's number? (-1 to exit): ";
	cin >> saleID;

	if (saleID == -1) {
		cout << "Exiting...\n";
	}

	return saleID;
}

void getProductCost(array<array<int, columns>, rows>& sales, int row) {
	int item{ 1 };
	int cost{};

	while (item <= 5) {
		cout << "Enter The Cost of Item " << item << ": ";
		cin >> cost;

		if (cost < 0) {
			cout << "Invalid Cost. Please try again.\n\n";
		}
		else {
			sales[row - 1][item - 1] = cost;
			item++;
		}
	}

	cout << endl;
}

int main() {
	array<array<int, columns>, rows> sales{};
	int saleInt{};

	saleInt = getID();
	while (saleInt != -1 ) {
		if (saleInt < 1 || saleInt > 4) {
			cout << "\nError: This saleperson's number is invalid. Please try again.\n\n";
		}
		else {
			getProductCost(sales, saleInt);
		}
		saleInt = getID();
	}

	cout << endl;
	cout << setw(20) << "Salesperson" << setw(20) << "Item" << setw(20) << "Cost\n";
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << setw(15) << i << setw(24) << j << setw(19) << sales[i - 1][j - 1] << endl;
		}
	}
	
	return 0;
}