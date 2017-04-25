#include <iostream>
#include <random>
#include "Scene.h"

const float Scene::SMALL_ASTEROID_PERCENT = 0.05;
const float Scene::MEDIUM_ASTEROID_PERCENT = 0.07;
const float Scene::LARGE_ASTEROID_PERCENT = 0.1;




int Scene::getRandomIntBetween (int min, int max) {
	std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<> distrib(min, max);

	return distrib(generator);
}

float Scene::getRandomFloatBetween (float min, float max) {
	std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_real_distribution<> distrib(min, max);

	return distrib(generator);
}

Vector Scene::getRandomVelocity (float minSpeed, float maxSpeed) {
	int randX = getRandomIntBetween(-sceneWidth, sceneWidth);
	int randY = getRandomIntBetween(-sceneHeight, sceneHeight);

	Vector v(randX, randY);
	v = v.getUnitVector();
	float randSpeed = getRandomFloatBetween(minSpeed, maxSpeed);
	v = randSpeed * v;

	return v;
}



void Scene::computeAsteroidSizes() {
	unsigned int minDim = min(sceneWidth, sceneHeight);
	// avoid having 0 size asteroids
	smallAsteroidRadius = 1 + SMALL_ASTEROID_PERCENT * minDim;
	mediumAsteroidRadius = 1 + MEDIUM_ASTEROID_PERCENT * minDim;
	largeAsteroidRadius = 1 + LARGE_ASTEROID_PERCENT * minDim;
}



Point Scene::wrapAroundView (Point p) {
	float pX = p.getX();
	float pY = p.getY();

	float newX, newY;
	// offset allows the asteroids to vanish completely before they get wrapped
	int offset = 100;

	if (pX > getWidth() + offset) 
		newX = 0.0 - offset;
	else if (pX < 0.0 - offset)
		newX = getWidth() + offset;
	else
		newX = pX;

	if (pY > getHeight() + offset)
		newY = 0.0 - offset;
	else if (pY < 0.0 - offset)
		newY = getHeight() + offset;
	else
		newY = pY;

	return Point(newX, newY);
}





Scene::Scene() : actors(), background(){
	setWidth(0);
	setHeight(0);
	setAnimationDelay(1000 / 60); //60 fps

	smallAsteroidRadius = 0;
	mediumAsteroidRadius = 0;
	largeAsteroidRadius = 0;
}

Scene::Scene (unsigned int width,
						  unsigned int height,
							unsigned int animDelay,
							Color bkg) : Scene() {
	setBackground(bkg);
	setWidth(width);
	setHeight(height);
	setAnimationDelay(animDelay);

	computeAsteroidSizes();
}

Scene::Scene (const Scene& s) : actors(s.actors), 
																background(s.background) {
	setWidth(s.sceneWidth);
	setHeight(s.sceneHeight);
	setAnimationDelay(s.animationDelay);
	
	smallAsteroidRadius = s.smallAsteroidRadius;
	mediumAsteroidRadius = s.mediumAsteroidRadius;
	largeAsteroidRadius = s.largeAsteroidRadius;
}



void Scene::advanceAnimation() {
	for (auto it = actors.begin(); it != actors.end(); it++) {
		it->move();
		it->setPosition( wrapAroundView(it->getPosition()) );
	}
}



void Scene::addAsteroid (const Asteroid& a) {
	actors.push_back(a);
}

void Scene::generateAsteroids (int count) {
	// update the sizes in case the scene dimensions changed
	computeAsteroidSizes();

	for (int i = 0; i < count; i++) {
		int size = getRandomIntBetween (smallAsteroidRadius, largeAsteroidRadius);

		int randX = getRandomIntBetween(0, sceneWidth);
		int randY = getRandomIntBetween(0, sceneHeight);

		Vector velocity = getRandomVelocity (2.0, 7.0);

		
		addAsteroid ( Asteroid(size, Point(randX, randY), velocity) );

	}
}

const std::list<Asteroid>& Scene::getAsteroids() const {
	return actors;
}



void Scene::setWidth (unsigned int width) {
	sceneWidth = width;
}

unsigned int Scene::getWidth() const {
	return sceneWidth;
}

void Scene::setHeight (unsigned int height) {
	sceneHeight = height;
}

unsigned int Scene::getHeight() const {
	return sceneHeight;
}

void Scene::setAnimationDelay (unsigned int delay) {
	animationDelay = delay;
}

unsigned int Scene::getAnimationDelay() const {
	return animationDelay;
}

void Scene::setBackground (Color c) {
	background = c;
}

Color Scene::getBackground() const {
	return background;
}



Scene& Scene::operator= (Scene& s) {
	actors = s.actors;
	sceneWidth = s.sceneWidth;
	sceneHeight = s.sceneHeight;
	background = s.background;
}
