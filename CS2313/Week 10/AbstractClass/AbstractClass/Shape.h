#ifndef SHAPE_H
#define SHAPE_H

class Shape //Abstract class
{
public:
	Shape();
	virtual double area() = 0;
	virtual ~Shape();
};

#endif // !SHAPE_H
