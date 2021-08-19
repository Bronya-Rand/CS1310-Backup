
#include <iostream>

using namespace std;

int main()
{
	int number1{ 0 };
	int number2{ 0 };

	cout << "Enter two numbers: ";
	cin >> number1 >> number2;

	if (number1 == number2)
	{
		cout << "Number 1  == Number 2\n";
	}

	if (number1 != number2)
	{
		cout << "Number 1  != Number 2\n";
	}

	if (number1 < number2)
	{
		cout << "Number 1  < Number 2\n";
	}

	if (number1 <= number2)
	{
		cout << "Number 1  <= Number 2\n";
	}

	if (number1 > number2)
	{
		cout << "Number 1  > Number 2\n";
	}

	if (number1 >= number2)
	{
		cout << "Number 1  >= Number 2\n";
	}

	return 0;
}