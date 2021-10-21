#include "Shape.h"
#include <iostream>

using namespace std;

void Shape::draw(){
	cout << "Draw the basic shape \n";
}

Shape::Shape() {
	cout << "Shape constructor of " << objectID << endl;
}

Shape::~Shape() {
	cout << "Shape destructor of " << objectID << endl;
}