#include <sstream>
#include "Movable.h"

Movable::Movable() : velocity(), position() {
}

Movable::Movable (const Point& p) : velocity(), position(p) {
}

Movable::Movable (const Point& p, const Vector& v) : velocity(v), position(p) {
}



Point Movable::getPosition() const {
	return position;
}

void Movable::setPosition (const Point& pos) {
	position = pos;
}


Vector Movable::getVelocity() const {
	return velocity;
}

void Movable::setVelocity (const Vector& v) {
	velocity = v;
}

float Movable::getSpeed() const {
	return velocity.getMagnitude();
}

void Movable::setSpeed (float speed) {
	Vector unit = velocity.getUnitVector();
	velocity = speed * unit;
}

void Movable::setDirection (const Point& p) {
	float currentSpeed = getSpeed();
	Vector newDirUnit(Vector(p).getUnitVector());

	velocity = currentSpeed * newDirUnit;
}



std::string Movable::toString() {
	std::ostringstream oString;

	oString << " Velocity vector : (" 
					<< velocity.getXComponent() << ','
					<< velocity.getYComponent() << ','
					<< velocity.getZComponent() << ')' << std::endl;

	oString << " Speed : " << getSpeed() << std::endl;
	oString << " Position : (" 
					<< position.getX() << ','
					<< position.getY() << ','
					<< position.getZ() << ')' << std::endl;

	return oString.str();

}
