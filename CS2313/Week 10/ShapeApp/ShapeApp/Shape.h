#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape {
public:
	string objectID = "ID: DEFAULT PARENT SHAPE";
	virtual void draw();
	Shape();
	~Shape();
};

#endif