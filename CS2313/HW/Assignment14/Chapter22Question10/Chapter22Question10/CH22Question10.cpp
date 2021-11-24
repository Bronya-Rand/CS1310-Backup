#include<iostream>
#include<bitset>

using namespace std;

// based off techiedelight code since I had no idea how this works (absent)
// https://www.techiedelight.com/reverse-bits-of-given-integer/
unsigned int reverseBits(unsigned int c1) {
	unsigned int ans = 0;
	for (int i = 32; i > 0; i--) {
		if (c1 & 1) {
			ans = ans | (1 << i);
		}
		c1 >>= 1;
	}
	return ans;
}

int main()
{
	unsigned int ui1;
	cout << "Please enter a number to reverse: ";
	cin >> ui1;

	;
	cout << "Before: " << bitset<32>(ui1) << endl;
	cout << "After: " << bitset<32>(reverseBits(ui1)) << endl;

	return 0;
}
