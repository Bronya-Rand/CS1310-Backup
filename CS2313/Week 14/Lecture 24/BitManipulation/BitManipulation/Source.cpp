#include<iostream>
#include<bitset>
#include<iomanip>

using namespace std;
int main()
{
	int a = 29;
	int b = 45;

	bitset<8> x(a);
	bitset<8> y(b);

	cout << setw(10) << "X = " << x << endl << endl;
	cout << setw(10) << "Y = " << y << endl << endl;
	cout << "-----------------------------------------\n";

	cout << setw(10) << "X AND Y = " << (x & y) << endl << endl;
	cout << setw(10) << "X OR Y = " << (x | y) << endl << endl;
	cout << setw(10) << "X XOR Y = " << (x ^ y) << endl << endl;
	cout << setw(10) << "!X = " << (~x) << endl << endl;
	cout << setw(10) << "!Y = " << (~y) << endl << endl;

	cout << setw(10) << "X SHIFTED LEFT 3 TIMES = " << (x <<3) << endl << endl;
	cout << setw(10) << "Y SHIFTED RIGHT 3 TIMES = " << (y >> 3) << endl << endl;
	cout << "--------------------------------------------\n";

	char ch1 = 'a';
	char ch2 = 'b';

	int pack = ch1;
	pack = pack << 8;
	pack = pack | ch2;

	cout << "Pack = " << pack << endl;
	cout << "first byte of my pack = " << static_cast<char>(pack) << endl;
	return 0;
}
