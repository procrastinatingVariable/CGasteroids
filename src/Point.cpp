#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}

Point::Point (float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point (const Point& p) {
	x = p.getX();
	y = p.getY();
	z = p.getZ();
}



float* Point::get2DPointArray() const {
	float* a = new float[2];
	a[0] = x;
	a[1] = y;

	return a;
}

float* Point::get3DPointArray() const {
	float* a = new float[3];
	a[0] = x;
	a[1] = y;
	a[2] = z;

	return a;
}



void Point::setX (float value) {
	x = value;
}

float Point::getX() const {
	return x;
}

void Point::setY (float value) {
	y = value;
}

float Point::getY() const {
	return y;
}

void Point::setZ (float value) {
	z = value;
}

float Point::getZ() const {
	return z;
}



void Point::scale (float value) {
	x *= value;
	y *= value;
	z *= value;
}


Point& Point::operator= (const Point& p) {
	x = p.x;
	y = p.y;
	z = p.z;

	return *this;
}

Point operator* (float c, const Point& p) {
	return Point (c * p.x, c * p.y, c * p.z);
}
