
#include <iostream>

#include ".\invoice.h"

using namespace std;

int main()
{
	string itemNumber;
	string itemDescription;
	int howMany{};
	int cost{};

	cout << "What is the part number of your item?: ";
	cin >> itemNumber;

	cout << "What is the part description of your item?: ";
	cin >> itemDescription;

	cout << "How many did you buy?: ";
	cin >> howMany;

	cout << "How much did it cost? (whole numbers only): ";
	cin >> cost;
	
	Invoice inv(itemNumber, itemDescription, howMany, cost);
	cout << "The total cost of your invoice is: $" << inv.getInvoiceAmount() << endl;

	cout << "\nSet price to $-20\n";
	inv.setPrice(-20);
	cout << "The total cost of your invoice is: $" << inv.getInvoiceAmount() << endl;

	cout << "Reset price\n";
	inv.setPrice(20);

	cout << "\nSet quantity to -5\n";
	inv.setQuantity(-5);
	cout << "The total cost of your invoice is: $" << inv.getInvoiceAmount() << endl;

	cout << "Reset quantity\n\n";
	inv.setQuantity(5);

	cout << "The part description is " << inv.getPartDescription() << endl;
	cout << "The part number is " << inv.getPartNumber() << endl; 

	cout << "\nSet part number and description to a familiar song.\n";
	inv.setPartNumber("867-5309");
	inv.setPartDescription("Some Random Song");
	cout << "The part description is " << inv.getPartDescription() << endl;
	cout << "The part number is " << inv.getPartNumber() << endl;
}