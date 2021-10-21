#include "Circle.h"

Circle::Circle() {

}

double Circle::area() {
	int radius{ 3 };
	return 3.14 * (radius * radius);
}

Circle::~Circle() {

}