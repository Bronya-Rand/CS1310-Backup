
#include <iostream>

using namespace std;

int main()
{
	//First way to initialize variables

	/*int number1 = 0;
	int number2 = 0;
	int sum;*/



	//List initialization
	int number1{ 0 };
	int number2{ 0 };
	int sum{ 0 };

	cout << "Enter first number: ";
	cin >> number1;

	cout << "Enter second number: ";
	cin >> number2;

	sum = number1 + number2;

	cout << "My sum is equal to " << sum << endl;
	return 0;
}