#include <cmath>
#include "Vector.h"

Vector::Vector() : endPoint() {
}

Vector::Vector (const Point& e) : endPoint(e){
}

Vector::Vector (double x, double y, double z) : endPoint(x, y, z) {
}

Vector::Vector (const Vector& v) : Vector(v.getEndPoint()) {
}



void Vector::setXComponent (double x) {
	endPoint.setX(x);
}

double Vector::getXComponent() const {
	return endPoint.getX();
}

void Vector::setYComponent (double y) {
	endPoint.setY(y);
}

double Vector::getYComponent() const {
	return endPoint.getY();
}

void Vector::setZComponent (double z) {
	endPoint.setZ(z);
}

double Vector::getZComponent() const {
	return endPoint.getZ();
}



void Vector::setEndPoint (const Point& endPoint) {
	this->endPoint = endPoint;
}

Point Vector::getEndPoint() const {
	return endPoint;
}


double Vector::getMagnitude() const {
	double xSquare = std::pow(endPoint.getX(), 2);
	double ySquare = std::pow(endPoint.getY(), 2);
	double zSquare = std::pow(endPoint.getZ(), 2);

	return std::sqrt(xSquare + ySquare + zSquare);
}



Vector& Vector::operator= (const Vector& v) {
	setEndPoint(v.getEndPoint());

	return *this;
}

Vector operator+ (const Vector& a, const Vector& b) {
	double aX = a.getEndPoint().getX();
	double aY = a.getEndPoint().getY();
	double aZ = a.getEndPoint().getZ();

	double bX = b.getEndPoint().getX();
	double bY = b.getEndPoint().getY();
	double bZ = b.getEndPoint().getZ();

	return Vector(Point(aX + bX, aY + bY, aZ + bZ));
}

Vector operator* (double scalar, const Vector& a) {
	double newX = a.getEndPoint().getX() * scalar;
	double newY = a.getEndPoint().getY() * scalar;
	double newZ = a.getEndPoint().getZ() * scalar;

	return Vector(Point(newX, newY, newZ));
}

Vector Vector::crossProduct (const Vector& v) {
	double x1 = endPoint.getX();
	double y1 = endPoint.getY();
	double z1 = endPoint.getZ();

	double x2 = v.endPoint.getX();
	double y2 = v.endPoint.getY();
	double z2 = v.endPoint.getZ();

	double newX = y1 * z2 - y2 * z1;
	double newY = - (x1 * z2 - x2 * z1);
	double newZ = x1 * y2 - x2 * y1;

	return Vector(Point(newX, newY, newZ));
}



Vector Vector::getUnitVector() const {
	double thisMagnitude = getMagnitude();
	if (thisMagnitude != 0) {
		Vector unit((1/getMagnitude()) * *this);
		return unit;
	}
	// return empty vector if magnitude is 0
	return Vector();
}



Vector Vector::rotate2D (double angle) {
	angle = MATH_RADIANS(angle);
	double cosAngle = std::cos(angle);
	double sinAngle = std::sin(angle);
	
	double currentX = endPoint.getX();
	double currentY = endPoint.getY();
	double newX = currentX * cosAngle - currentY * sinAngle;
	double newY = currentX * sinAngle + currentY * cosAngle;

	endPoint.setX(newX);
	endPoint.setY(newY);

	return endPoint;
}

