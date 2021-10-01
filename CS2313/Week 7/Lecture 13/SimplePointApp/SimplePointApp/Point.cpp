
#include "Point.h"
#include <sstream>

using namespace std;

Point::Point(int x, int y) {
	xCoordinate = x;
	yCoordinate = y;
}

string Point::toString() {
	ostringstream out;
	out << "(" << xCoordinate << ", " << yCoordinate << ")";
	return out.str();
}

Point Point::add(Point& p) {
	Point temp{ *this };
	temp.xCoordinate += p.xCoordinate;
	temp.yCoordinate += p.yCoordinate;
	return temp;
}

Point Point::operator+(Point& p) {
	Point temp{ *this };
	temp.xCoordinate += p.xCoordinate;
	temp.yCoordinate += p.yCoordinate;
	return temp;
}