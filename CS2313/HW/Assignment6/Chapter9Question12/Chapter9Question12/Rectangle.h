
#include <string>

#ifndef RECT_H
#define RECT_H

class Rectangle {
public:
	Rectangle(float len1, float len2, float wid1, float wid2);
	float getLength();
	float getWidth();
	void setDimensions(float l1, float l2, float w1, float w2);
	std::string getPerimeter();
	std::string getArea();
private:
	float length1{ 1.0 };
	float width1{ 1.0 };
	float length2{ 1.0 };
	float width2{ 1.0 };
};

#endif