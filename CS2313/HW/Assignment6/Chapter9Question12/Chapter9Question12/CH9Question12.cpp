
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
	Rectangle rect(7, 7, 5, 5);
	cout << "Current L: " << rect.getLength() << endl;
	cout << "Current W: " << rect.getWidth() << endl;
	cout << rect.getPerimeter();
	cout << rect.getArea();

	Rectangle rect2 (static_cast<float>(7.4), static_cast<float>(5.45), static_cast<float>(5.45), static_cast<float>(7.4));
	cout << "\nChanged Length and Width\n";
	cout << "New L: " << rect2.getLength() << endl;
	cout << "New W: " << rect2.getWidth() << endl;
	cout << rect2.getPerimeter();
	cout << rect2.getArea();
	return 0;
}