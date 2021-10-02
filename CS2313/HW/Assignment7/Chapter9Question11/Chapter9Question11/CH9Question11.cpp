
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
	Rectangle rect(5, 7);
	cout << "Current L: " << rect.getLength() << endl;
	cout << "Current W: " << rect.getWidth() << endl;
	cout << rect.getPerimeter();
	cout << rect.getArea();

	rect.setLength(static_cast<float>(5.75));
	rect.setWidth(static_cast<float>(16.75));
	cout << "\nChanged Length and Width\n";
	cout << "New L: " << rect.getLength() << endl;
	cout << "New W: " << rect.getWidth() << endl;
	cout << rect.getPerimeter();
	cout << rect.getArea();
	return 0;
}