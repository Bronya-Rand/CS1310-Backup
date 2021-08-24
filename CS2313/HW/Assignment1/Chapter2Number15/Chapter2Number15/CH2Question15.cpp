
#include <iostream>

using namespace std;

int main() {

	int x{};

	x = 7 + 3 * 6 / 2 - 1;
	cout << "The total of \"x\" is: " << x << endl;
	cout << "The order is (3 * 6) / 2, which is then added by 7 and then subtracted by 1.\n";

	x = 2 % 2 + 2 * 2 - 2 / 2;
	cout << "The total of \"x\" is: " << x << endl;
	cout << "The order is (2 * 2), then (2 % 2) and (2 / 2), which is then added by 2.\n";

	x = (3 * 9 * (3 + (9 * 3 / (3))));
	cout << "The total of \"x\" is: " << x << endl;
	cout << "The order is (9 * 3 / 3), then added by 3, then multipled by 9, then 3.\n";
}