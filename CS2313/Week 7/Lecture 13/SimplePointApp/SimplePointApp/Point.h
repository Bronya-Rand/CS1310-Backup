
#include <string>

using namespace std;

#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point(int x, int y);
	string toString();
	Point add(Point& p);

	Point operator+(Point& p);
private:
	int xCoordinate;
	int yCoordinate;
};

#endif