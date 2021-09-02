
#include <iostream>

using namespace std;

inline double cube(const double side) {
	return side * side * side;
}

int main() {
	double side;
	cout << "Enter a side: ";
	cin >> side;

	cout << side << "^3 = " << cube(side) << endl;

	return 0;
}