#include "Circle.h"
#include <iostream>

using namespace std;

void Circle::draw() {
	cout << "Draw basic circle \n";
}

Circle::Circle() {
	cout << "Circle constructor of " << objectID << endl;
}

Circle::~Circle() {
	cout << "Circle destructor of " << objectID << endl;
}