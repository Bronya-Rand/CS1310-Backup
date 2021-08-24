
#include <iostream>
#define PI 3.14159

using namespace std;

int main()
{
	int radius{};
	double result{};

	cout << "Type in the radius of your circle: ";
	cin >> radius;

	result = 2 * PI * radius * radius;
	cout << "The radius of your circle is: " << result << endl;
}