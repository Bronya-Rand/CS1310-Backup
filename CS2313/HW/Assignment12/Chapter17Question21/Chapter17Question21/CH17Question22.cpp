
#include<stdio.h>
#include<iostream>
#include "ZeroException.h"

using namespace std;

double quotient(int numerator, int denominator)
{
	if (denominator == 0)
		throw ZeroException();

	return static_cast<double>(numerator) / denominator;
}
int main()
{
	int x, y;

	double result;

	cout << "Enter two integers ( CTRL+Z to exit ): ";
	while (cin >> x >> y)
	{
		try
		{
			result = quotient(x, y);
			cout << x << " / " << y << " = " << result << endl;
		}
		catch (runtime_error& error)
		{
			cout << "Exception occurred: " << error.what() << endl;
		}
		cout << "Enter two integers ( CTRL+Z to exit ): ";
	}
}