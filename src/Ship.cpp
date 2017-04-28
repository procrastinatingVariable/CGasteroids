#include <iostream>
#include <cmath>
#include <GL/freeglut.h>
#include "Ship.h"
//#include "Bullet.h"
#include "Point.h"



unsigned int Ship::DEFAULT_WIDTH = 20;
unsigned int Ship::DEFAULT_HEIGHT = 30;


Ship::Ship (double rotation, const Point& pos) : 
																	Kinematic(pos, Vector(0.0, 0.001)), Polygon(), 
																	color(1.0, 1.0, 1.0) {
	setRotation(rotation);
	setAcceleration(0.0);
	setWidth(Ship::DEFAULT_WIDTH);
	setHeight(Ship::DEFAULT_HEIGHT);
	createShape();
}

Ship::Ship (const Ship& ship) : Kinematic(ship.getPosition(), ship.getVelocity()),
																Polygon(ship.getVertices()), 
																color(ship.getColor()) {

	setRotation(ship.getRotation());
	setAcceleration(0.0);
	setWidth(ship.getWidth());
	setHeight(ship.getHeight());
}


Bullet Ship::shoot() {
	Vector shipVelUnit = getVelocity().getUnitVector();
	Vector tipOfShip = Vector(getPosition()) + shipVelUnit;
	Vector bulletVelocity = getVelocity();

	Bullet b ( 3.0, tipOfShip.getEndPoint(), Vector(bulletVelocity) );
	b.setSpeed( getSpeed() + 10.0 );

	return b;
}



void Ship::setColor (const Color& color) {
	this->color = color;
}

Color Ship::getColor() const {
	return color;
}



void Ship::setWidth (unsigned int width) {
	this->width = width;
}

unsigned int Ship::getWidth() const {
	return width;
}

void Ship::setHeight (unsigned int height) {
	this->height = height;
}

unsigned int Ship::getHeight() const {
	return height;
}



void Ship::rotate (double angle) {
	setRotation( getRotation() + angle );
	setVelocity( getVelocity().rotate2D(-angle) );
}

void Ship::setRotation (double angle) {
	this->rotation = angle;
}

double Ship::getRotation() const {
	return rotation;
}



void Ship::accelerate (double ammount) {
	setAcceleration(getAcceleration() + ammount);
}

void Ship::setAcceleration (double accel) {
	this->acceleration = accel;
}

double Ship::getAcceleration() const {
	return acceleration;
}



Point Ship::getCircumcenter() const {
	Point A(vertices[0]);
	Point B(vertices[1]);
	Point C(vertices[2]);

	double delta = 2 * (A.getX() * (B.getY() - C.getY()) +
											B.getX() * (C.getY() - A.getY()) +
											C.getX() * (A.getY() - B.getY()) );
	double centerX =  
						1.0 / delta * (
						( std::pow(A.getX(), 2) + std::pow(A.getY(), 2) ) * (B.getY() - C.getY()) +
						( std::pow(B.getX(), 2) + std::pow(B.getY(), 2) ) * (C.getY() - A.getY()) +
						( std::pow(C.getX(), 2) + std::pow(C.getY(), 2) ) * (A.getY() - B.getY())
						);
	double centerY = 
						1.0 / delta * (
						( std::pow(A.getX(), 2) + std::pow(A.getY(), 2) ) * (C.getX() - B.getX()) +
						( std::pow(B.getX(), 2) + std::pow(B.getY(), 2) ) * (A.getX() - C.getX()) +
						( std::pow(C.getX(), 2) + std::pow(C.getY(), 2) ) * (B.getX() - A.getX())
						);

	return Point(centerX, centerY);
}



/* the ships coordinates are normalized
 * its position will be its center of gravity
 * its tip will be 2/3 of its height from the center of gravity (origin of the plane)
 * while its bottom line will be 1/3 of its height
 */
void Ship::createShape() {
	vertices.clear();


	double shipHeight = getHeight();

	double tipY = 2.0/3.0 * shipHeight;

	double shipWidth = getWidth();
	double bEdgeY = -1.0/3.0 * shipHeight;
	double bTipRightX = shipWidth / 2;
	double bTipLeftX = -bTipRightX;

	Point tip (0.0, tipY);
	Point bLeftTip (bTipLeftX, bEdgeY);
	Point bRightTip (bTipRightX, bEdgeY);

	pushVertex(tip);
	pushVertex(bLeftTip);
	pushVertex(bRightTip);
	
}

void Ship::move() {
	if (getAcceleration() == 0) {
		if ( std::floor(getSpeed()) > 0.05 )
			setSpeed(getSpeed() * SPEED_DECREMENT);
	} else {
		double newSpeed = getSpeed() + 6.0/100.0 * getAcceleration();
		newSpeed = newSpeed > SHIP_MAX_SPEED  ? SHIP_MAX_SPEED : newSpeed;
		setSpeed(newSpeed);
	}

	// apply velocity
	Vector vel = getVelocity();
	Vector posVector( getPosition() );
	Vector newPosVector = vel + posVector;

	setPosition(newPosVector.getEndPoint());
}

void Ship::draw() {
	if (glutGetWindow() == 0) return;

	glLineWidth( getLineWidth() );

	double color[3];
	getColor().getRGBDoubleArray( color );
	glColor3dv(color);

	if ( !isFilled() ) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	glPushMatrix();
	Point pos = getPosition();
	glTranslated (pos.getX(), pos.getY(), pos.getZ());
	glRotated( rotation, 0.0, 0.0, -1.0);

	glBegin(GL_TRIANGLES);

		for (auto it : vertices) {
			glVertex2d( it.getX(), it.getY() );
		}

	glEnd();

	glPopMatrix();

}


