/*
Chapter 3 Question 10 Header File
Author: Azariel Del Carmen
*/

#include <iostream>
#include <string>

using namespace std;

class Invoice {
	string partNumber;
	string partDescription;
	int quantity{};
	int price{};

public:

	Invoice(string partNum, string partDescriptor, int howMany, int cost) {
		partNumber = partNum;
		partDescription = partDescriptor;
		if (howMany < 0) {
			quantity = 0;
		}
		else {
			quantity = howMany;
		}
		if (cost < 0) {
			price = 0;
		}
		else {
			price = cost;
		}
	}

	int getInvoiceAmount() {
		if (price < 0) {
			price = 0;
		}
		if (quantity < 0) {
			quantity = 0;
		}

		return price * quantity;
	}

	int getPrice() {
		return price;
	}

	int getQuantity() {
		return price;
	}

	string getPartNumber() {
		return partNumber;
	}

	string getPartDescription() {
		return partDescription;
	}

	void setPartNumber(string partNum) {
		partNumber = partNum;
	}

	void setPartDescription(string partDescriptor) {
		partDescription = partDescriptor;
	}

	void setQuantity(int howMany) {
		if (howMany < 0) {
			quantity = 0;
		}
		else {
			quantity = howMany;
		}
	}

	void setPrice(int cost) {
		if (cost < 0) {
			price = 0;
		}
		else {
			price = cost;
		}
	}
};