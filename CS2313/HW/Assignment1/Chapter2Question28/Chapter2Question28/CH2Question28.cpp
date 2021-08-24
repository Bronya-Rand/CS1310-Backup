/*
Chapter 2 Question 28
Author: Azariel Del Carmen
*/

#include <iostream>

using namespace std;

int main()
{
	int x{};

	cout << "Please provide a five digit integer: ";
	cin >> x;
	
	cout << "Your number seperated into 5 digits is: \n";
	// based off a StackExchange forum post answer of the breakdown problem
	cout << x /  10000 << "\t" << (x % 10000) / 1000 << "\t" << ((x % 10000) % 1000) / 100 << "\t" << (((x % 10000) % 1000) % 100) / 10 << "\t" << ((((x % 10000) % 1000) % 100) % 10) << endl;
}