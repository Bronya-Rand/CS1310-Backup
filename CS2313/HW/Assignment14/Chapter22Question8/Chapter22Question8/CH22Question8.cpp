#include<iostream>
#include<iomanip>
#include<bitset>

using namespace std;

unsigned int packCharacters(char c1, char c2, char c3, char c4) {
	unsigned int result = c1;

	bitset<8> a(c1);
	bitset<8> b(c2);
	bitset<8> c(c3);
	bitset<8> d(c4);
	cout << "B - c1: " << a << endl;
	cout << "B - c2: " << b << endl;
	cout << "B - c3: " << c << endl;
	cout << "B - c4: " << d << endl;

	bitset<8> e(result);
	cout << "A - 1st byte: " << e << endl;
	result = result << 8;
	result = result | c2;
	e = result;
	cout << "A - 2nd byte: " << e << endl;
	result = result << 8;
	result = result | c3;
	e = result;
	cout << "A - 3rd byte: " << e << endl;
	result = result << 8;
	result = result | c4;
	e = result;
	cout << "A - 4th byte: " << e << endl;
	result = result << 8;

	return result;
}

int main()
{
	char ch1;
	char ch2;
	char ch3;
	char ch4;

	cout << "Please enter a 4 characters: ";
	cin >> ch1 >> ch2 >> ch3 >> ch4;

	cout << "The packed result of " << ch1 << ch2 << ch3 << ch4 << " is: " << packCharacters(ch1, ch2, ch3, ch4) << endl;

	return 0;
}
