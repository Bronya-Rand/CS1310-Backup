
#include <iostream>
#include "Shape.h"
#include "Circle.h"

using namespace std;

int main() {
	//Square squareObj; //ERROR: you cannot take a object from a abstract class
	Circle circleObj;

	cout << "Area of Circle = " << circleObj.area() << endl;
}