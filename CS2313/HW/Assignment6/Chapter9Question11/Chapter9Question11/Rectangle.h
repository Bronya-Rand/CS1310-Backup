
#include <string>

#ifndef RECT_H
#define RECT_H

class Rectangle {
public:
	Rectangle(float l, float w);
	float getLength();
	float getWidth();
	void setLength(float l);
	void setWidth(float w);
	std::string getPerimeter();
	std::string getArea();
private:
	float length{ 1.0 };
	float width{ 1.0 };
};

#endif