#include <sstream>
#include "Kinematic.h"

Kinematic::Kinematic() : velocity(), position() {
}

Kinematic::Kinematic (const Point& p) : velocity(), position(p) {
}

Kinematic::Kinematic (const Point& p, const Vector& v) : velocity(v), position(p) {
}

Kinematic::Kinematic (const Kinematic& k) : velocity(k.getVelocity()), 
																						position(k.getPosition()) {
}



Point Kinematic::getPosition() const {
	return position;
}

void Kinematic::setPosition (const Point& pos) {
	position = pos;
}


Vector Kinematic::getVelocity() const {
	return velocity;
}

void Kinematic::setVelocity (const Vector& v) {
	velocity = v;
}

double Kinematic::getSpeed() const {
	return velocity.getMagnitude();
}

void Kinematic::setSpeed (double speed) {
	Vector unit = velocity.getUnitVector();
	velocity = speed * unit;
}

void Kinematic::setDirection (const Point& p) {
	double currentSpeed = getSpeed();
	Vector newDirUnit(Vector(p).getUnitVector());

	velocity = currentSpeed * newDirUnit;
}



std::string Kinematic::toString() {
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
