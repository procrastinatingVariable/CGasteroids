#include <iostream>
#include <GL/freeglut.h>
#include <random>
#include "Asteroid.h"


unsigned int Asteroid::SIZE_SMALL = 10;
unsigned int Asteroid::SIZE_MEDIUM = 20;
unsigned int Asteroid::SIZE_BIG = 35;



int Asteroid::getRandomIntBetween (int min, int max) {
	std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<> distrib(min, max);

	return distrib(generator);
}

double Asteroid::getRandomFloatBetween (double min, double max) {
	std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_real_distribution<> distrib(min, max);

	return distrib(generator);
}



Asteroid::Asteroid() : Polygon(), Kinematic(), color(1.0, 1.0, 1.0) {
	setSize(0);
}

Asteroid::Asteroid (double size, const Point& pos) : Polygon(), 
																										 Kinematic(pos),
																										 color(1.0, 1.0, 1.0) {
	setSize(size);
	createShape();
}

Asteroid::Asteroid (double size, const Point& pos, const Vector& vel) :
																											Polygon(),
																											Kinematic(pos, vel),
																											color(1.0, 1.0, 1.0) {

	setSize(size);
	createShape();
}



bool Asteroid::hasCollided (const Ship& s) {
	int aSize = getSize();

	Point sPos (s.getCircumcenter());
	Point aPos (getPosition());
	
	if ( Point::distance(sPos, aPos) <= aSize )
		return 1;

	return 0;
}

bool Asteroid::hasCollided (const Bullet& b) {
	int aSize = getSize();

	Point bPos (b.getPosition());
	Point aPos (getPosition());

	if ( Point::distance(aPos, bPos) <= aSize ) 
		return 1;

	return 0;
}


void Asteroid::setColor (const Color& color) {
	this->color = color;
}

Color Asteroid::getColor() const {
	return color;
}



void Asteroid::setSize (double size) {
	this->size = size;
}

double Asteroid::getSize() const {
	return size;
}



/* generates the asteroid by picking the middle of two random
 * edges of an octagon and bringing them closer to the center
 * by a random amount
 */
void Asteroid::createShape() {
	vertices.clear();

	// generate the octagon
	Vector drawer( Point(size, 0.0));
	int numOfVertices = 8;
	for (int i = 0; i < numOfVertices; i++) {
		pushVertex(drawer.getEndPoint());
		drawer.rotate2D(45);
	}
	
	// generate random mid points vectors and scale them
	int rand1 = getRandomIntBetween(0, 7);
	int rand2;
	while ( (rand2 = getRandomIntBetween(0,7)) == rand1){}

	double randAngle1 = 45.0 / 2.0 + rand1 * 45.0;
	double randAngle2 = 45.0 / 2.0 + rand2 * 45.0;

	Vector concave1( Point(size, 0) );
	concave1.rotate2D(randAngle1);
	concave1 = getRandomFloatBetween(0.4, 0.9) * concave1;

	Vector concave2( Point(size, 0) );
	concave2.rotate2D(randAngle2);
	concave2 = getRandomFloatBetween(0.4, 0.9) * concave2;

	// we first insert the one with the heighest order as to 
	// ignore the shifting of the values
	if (rand1 > rand2) {
		insertVertex(concave1.getEndPoint(), rand1 + 1);
		insertVertex(concave2.getEndPoint(), rand2 + 1);
	} else {
		insertVertex(concave2.getEndPoint(), rand2 + 1);
		insertVertex(concave1.getEndPoint(), rand1 + 1);
	}

}

void Asteroid::move() {
	double newX = getPosition().getX() + getVelocity().getXComponent();
	double newY = getPosition().getY() + getVelocity().getYComponent();
	double newZ = getPosition().getZ() + getVelocity().getZComponent();

	setPosition( Point (newX, newY, newZ) );
}

void Asteroid::draw() {
	// don't draw if there's not window
	if (glutGetWindow() == 0) return;

	glLineWidth( getLineWidth() );

	double color[3];
	getColor().getRGBDoubleArray( color );
	glColor3dv(color);

	if ( !isFilled() ) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	glPushMatrix();
	glTranslated (getPosition().getX(), getPosition().getY(), 0.0);
	
	glBegin(GL_POLYGON);
		
		for (auto it : vertices) {
			glVertex2d( it.getX(), it.getY() );
		}

	glEnd();

	glPopMatrix();
}



