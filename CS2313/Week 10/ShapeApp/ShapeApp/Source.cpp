#include <iostream>
#include "Shape.h"
#include "Circle.h"

using namespace std;

int main() {
	//Step 1
	Shape shapeObj;
	shapeObj.objectID = "ID: ShapeObj";

	cout << endl;

	//Step 2
	Circle circleObj;
	circleObj.objectID = "ID: CircleObj";

	cout << endl;

	//Step 3
	Shape* circlePtr = new Circle();
	circlePtr->objectID = "ID: circlePtr";
	delete circlePtr;
}