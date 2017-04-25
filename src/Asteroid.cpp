#include <random>
#include "Asteroid.h"



int Asteroid::getRandomIntBetween (int min, int max) {
	std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<> distrib(min, max);

	return distrib(generator);
}

float Asteroid::getRandomFloatBetween (float min, float max) {
	std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_real_distribution<> distrib(min, max);

	return distrib(generator);
}

Asteroid::Asteroid() : Movable(), Drawable() {
	size = 0;
}

Asteroid::Asteroid (float size,
										const Point& position,
										const Vector& velocity) : Movable(position, velocity) {
	setSize(size);
	generateVertices();
}



void Asteroid::setSize (float size) {
	if (size < 0) {
		this->size = 0;
	}
	float oldSize = this->size;
	this->size = size;
	// update each point's distance from the center
	for (Point& v : vertices) {
		v.scale(size / oldSize);
	}
}

float Asteroid::getSize() const {
	return size;
}


/* generates the asteroid by picking the middle of two random
 * edges of an octagon and bringing them closer to the center
 * by a random amount
 */
void Asteroid::generateVertices() {
	vertices.clear();

	// generate the octagon
	Vector drawer( Point(size, 0.0));
	int numOfVertices = 8;
	for (int i = 0; i < numOfVertices; i++) {
		pushVertex(drawer.getEndPoint());
		drawer.rotate2D(MATH_RADIANS(45));
	}
	
	// generate random mid points vectors and scale them
	int rand1 = getRandomIntBetween(0, 7);
	int rand2;
	while ( (rand2 = getRandomIntBetween(0,7)) == rand1){}

	float randAngle1 = 45.0 / 2.0 + rand1 * 45.0;
	float randAngle2 = 45.0 / 2.0 + rand2 * 45.0;

	Vector concave1( Point(size, 0) );
	concave1.rotate2D( MATH_RADIANS(randAngle1) );
	concave1 = getRandomFloatBetween(0.4, 0.9) * concave1;

	Vector concave2( Point(size, 0) );
	concave2.rotate2D( MATH_RADIANS(randAngle2) );
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
	int newX = getPosition().getX() + getVelocity().getXComponent();
	int newY = getPosition().getY() + getVelocity().getYComponent();
	int newZ = getPosition().getZ() + getVelocity().getZComponent();

	setPosition( Point (newX, newY, newZ) );
}



