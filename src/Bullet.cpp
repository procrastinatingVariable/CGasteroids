#include <GL/freeglut.h>
#include "Bullet.h"


Bullet::Bullet() : Kinematic(), color(1.0, 1.0, 1.0), size(1.0) {
}

Bullet::Bullet (double size, const Point& pos, const Vector& vel) :
																										Kinematic(pos, vel),
																										color(1.0, 1.0, 1.0),
																										size(size) {
}



void Bullet::setColor (const Color& color) {
	this->color = color;
}

Color Bullet::getColor() const {
	return color;
}



void Bullet::setSize (double size) {
	this->size = size >= 1 ? size : 1.0;
}

double Bullet::getSize() const {
	return size;
}


void Bullet::move() {
	setPosition( (Vector(getPosition()) + getVelocity()).getEndPoint() );
}

void Bullet::draw() {
	glEnable(GL_POINT_SMOOTH);

	glPointSize(size);

	double color[3];
	getColor().getRGBDoubleArray(color);
	glColor3dv(color);

	glBegin(GL_POINTS);
		glVertex2d( getPosition().getX(), getPosition().getY() );
	glEnd();

	glDisable(GL_POINT_SMOOTH);

}
