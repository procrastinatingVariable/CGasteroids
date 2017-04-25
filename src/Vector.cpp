#include <cmath>
#include "Vector.h"

Vector::Vector() : endPoint() {

}

Vector::Vector (const Point& e) : endPoint(e){
}

Vector::Vector (float x, float y, float z) : endPoint(x, y, z) {
}

Vector::Vector (const Vector& v) : Vector(v.getEndPoint()) {
}



void Vector::setXComponent (float x) {
	endPoint.setX(x);
}

float Vector::getXComponent() const {
	return endPoint.getX();
}

void Vector::setYComponent (float y) {
	endPoint.setY(y);
}

float Vector::getYComponent() const {
	return endPoint.getY();
}

void Vector::setZComponent (float z) {
	endPoint.setZ(z);
}

float Vector::getZComponent() const {
	return endPoint.getZ();
}



void Vector::setEndPoint (const Point& endPoint) {
	this->endPoint = endPoint;
}

Point Vector::getEndPoint() const {
	return endPoint;
}


float Vector::getMagnitude() const {
	float xSquare = std::pow(endPoint.getX(), 2);
	float ySquare = std::pow(endPoint.getY(), 2);
	float zSquare = std::pow(endPoint.getZ(), 2);

	return std::sqrt(xSquare + ySquare + zSquare);
}



Vector& Vector::operator= (const Vector& v) {
	setEndPoint(v.getEndPoint());

	return *this;
}

Vector operator+ (const Vector& a, const Vector& b) {
	float aX = a.getEndPoint().getX();
	float aY = a.getEndPoint().getY();
	float aZ = a.getEndPoint().getZ();

	float bX = b.getEndPoint().getX();
	float bY = b.getEndPoint().getY();
	float bZ = b.getEndPoint().getZ();

	return Vector(Point(aX + bX, aY + bY, aZ + bZ));
}

Vector operator* (float scalar, const Vector& a) {
	float newX = a.getEndPoint().getX() * scalar;
	float newY = a.getEndPoint().getY() * scalar;
	float newZ = a.getEndPoint().getZ() * scalar;

	return Vector(Point(newX, newY, newZ));
}

Vector Vector::crossProduct (const Vector& v) {
	float x1 = endPoint.getX();
	float y1 = endPoint.getY();
	float z1 = endPoint.getZ();

	float x2 = v.endPoint.getX();
	float y2 = v.endPoint.getY();
	float z2 = v.endPoint.getZ();

	float newX = y1 * z2 - y2 * z1;
	float newY = - (x1 * z2 - x2 * z1);
	float newZ = x1 * y2 - x2 * y1;

	return Vector(Point(newX, newY, newZ));
}



Vector Vector::getUnitVector() const {
	float thisMagnitude = getMagnitude();
	if (thisMagnitude != 0) {
		Vector unit((1/getMagnitude()) * *this);
		return unit;
	}
	return Vector();
}



Vector Vector::rotate2D (float angle) {
	float cosAngle = std::cos(angle);
	float sinAngle = std::sin(angle);
	
	float currentX = endPoint.getX();
	float currentY = endPoint.getY();
	float newX = currentX * cosAngle - currentY * sinAngle;
	float newY = currentX * sinAngle + currentY * cosAngle;

	endPoint.setX(newX);
	endPoint.setY(newY);

	return endPoint;
}

