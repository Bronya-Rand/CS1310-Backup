
#include <iostream>

using namespace std;

int main() {
	char input{ 'a' };
	int data{};
	int a;
	int b;
	int c;
	int d;

	while (input != 'e' && input != 'E' && input != 'd' && input != 'D') {
		cout << "Do you want to encrypt or decrypt data? (e/d): ";
		cin >> input;
	}
	if (input == 'e' || input == 'E') {
		while (data < 1000 || data > 9999) {
			cout << "Enter the integer you want to encrypt: ";
			cin >> data;
		}
	}
	else {
		cout << "Enter the integer you want to decrypt: ";
		cin >> data;
	}
	
	a = data % 10;
	b = (data / 10) % 10;
	c = (data / 100) % 10;
	d = (data / 1000) % 10;
	if (input == 'e' || input == 'E') {
		a = (a + 7) % 10;
		b = (b + 7) % 10;
		c = (c + 7) % 10;
		d = (d + 7) % 10;
	}
	else {
		if (a < 7)
		{
			a += 10;
		}
		if (b < 7)
		{
			b += 10;
		}
		if (c < 7)
		{
			c += 10;
		}
		if (d < 7)
		{
			d += 10;
		}
		a -= 7;
		b -= 7;
		c -= 7;
		d -= 7;
	}

	cout << "Your new encrpyted/decrpyted data is: " << c << d << a << b << endl;

	return 0;

}