
#include "Point.h"
#include <iostream>

using namespace std;

int main() {
	Point p1{ 3, 5 };
	Point p2{ p1 };
	Point p3 = p1;

	cout << p1.toString() << endl;
	cout << p2.toString() << endl;
	cout << p3.toString() << endl;

	cout << "---------------------- Add points using function Add ---------------------\n\n";
	Point p4{ 2, 7 };
	Point p5 = p1.add(p4);
	cout << p1.toString() << " + " << p4.toString() << " = " << p5.toString() << endl;

	cout << "--------------------- Add points using the operator + ---------------------\n\n";
	p5 = p1 + p4; //operator overloading for "+"...
	cout << p1.toString() << " + " << p4.toString() << " = " << p5.toString() << endl;

	return 0;
}