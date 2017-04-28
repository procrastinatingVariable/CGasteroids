#include <cmath>
#include "Point.h"



double Point::distance (const Point& a, const Point& b) {
	double aX = a.getX();
	double aY = a.getY();
	double aZ = a.getZ();

	double bX = b.getX();
	double bY = b.getY();
	double bZ = b.getZ();

	return std::sqrt( std::pow(bX - aX, 2) + 
										std::pow(bY - aY, 2) +
										std::pow(bZ - aZ, 2) );
}





Point::Point() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Point::Point (double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point (const Point& p) {
	x = p.getX();
	y = p.getY();
	z = p.getZ();
}



void Point::get2DPointArray (double array[2]) const {
	array[0] = getX();
	array[1] = getY();
}

void Point::get3DPointArray (double array[3]) const {
	array[0] = getX();
	array[1] = getY();
	array[2] = getZ();
}



void Point::setX (double value) {
	x = value;
}

double Point::getX() const {
	return x;
}

void Point::setY (double value) {
	y = value;
}

double Point::getY() const {
	return y;
}

void Point::setZ (double value) {
	z = value;
}

double Point::getZ() const {
	return z;
}



void Point::scale (double value) {
	x *= value;
	y *= value;
	z *= value;
}


Point& Point::operator= (const Point& p) {
	setX(p.x);
	setY(p.y);
	setZ(p.z);

	return *this;
}

Point operator* (double c, const Point& p) {
	double x = c * p.getX();
	double y = c * p.getY();
	double z = c * p.getZ();

	return Point(x, y, z);
}

