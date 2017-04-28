#include <iostream>
#include <random>
#include "Scene.h"



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

Point Scene::wrapAroundView (Point p) {
	float pX = p.getX();
	float pY = p.getY();

	float newX, newY;
	// offset allows the asteroids to vanish completely before they get wrapped
	int offset = Asteroid::SIZE_BIG;

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





Scene::Scene() :asteroids(), bullets(), ship(0.0, Point(0.0, 0.0)), background() {
	setWidth(0);
	setHeight(0);
	setAnimationDelay(1000 / 60); //60 fps
}

Scene::Scene (unsigned int width,
						  unsigned int height,
							unsigned int animDelay,
							Color bkg) : Scene() {
	setBackground(bkg);
	setWidth(width);
	setHeight(height);
	setAnimationDelay(animDelay);

	ship.setPosition( Point( width/2, height/2 ));
}

Scene::Scene (Scene& s) : asteroids(s.asteroids), 
													bullets(s.bullets),
													ship(s.getShip()),
													background(s.background) {
	setWidth(s.sceneWidth);
	setHeight(s.sceneHeight);
	setAnimationDelay(s.animationDelay);
}



void Scene::advanceAnimation() {
	// move actors
	for (auto it = asteroids.begin(); it != asteroids.end(); it++) {
		it->move();
		it->setPosition( wrapAroundView(it->getPosition()) );
	}

	for (auto it = bullets.begin(); it != bullets.end(); it++) {
		it->move();
		it->setPosition( wrapAroundView(it->getPosition()) );
		if (!isInScene(it->getPosition())) {
			auto s = it++;
			removeBullet(s);
		}
	}

	ship.move();
	ship.setPosition ( wrapAroundView(ship.getPosition()) );

	// check for collisions
	for (auto ita = asteroids.begin(); ita != asteroids.end(); ita++) {
		for (auto itb = bullets.begin(); itb != bullets.end(); itb++) {
			if (ita->hasCollided(*itb)) {
				auto toRemoveB = itb++;
				removeBullet(toRemoveB);
				
				auto toRemoveA = ita++;
				removeAsteroid(toRemoveA);
				break;
			}
		}

	}
}



void Scene::addAsteroid (const Asteroid& a) {
	asteroids.push_back(a);
}

void Scene::removeAsteroid (std::list<Asteroid>::iterator it) {
	if (!asteroids.empty()) 
		asteroids.erase(it);
}

void Scene::generateAsteroids (int count) {
	for (int i = 0; i < count; i++) {
		int randX = getRandomIntBetween(0, sceneWidth);
		int randY = getRandomIntBetween(0, sceneHeight);

		Vector velocity = getRandomVelocity (ASTEROID_MIN_SPEED, ASTEROID_MAX_SPEED);
		
		unsigned int size = getRandomIntBetween(Asteroid::SIZE_SMALL, Asteroid::SIZE_BIG);
		addAsteroid ( Asteroid(size, Point(randX, randY), velocity) );
	}

}



void Scene::addBullet (const Bullet& b) {
	bullets.push_back(b);
}

void Scene::removeBullet(std::list<Bullet>::iterator it) {
	if (!bullets.empty())
		bullets.erase(it);
}



Ship& Scene::getShip() {
	return ship;
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


bool Scene::isInScene (const Point& p) const {
	if (p.getX() > getWidth() || p.getX() < 0) return 0;
	if (p.getY() > getHeight() || p.getY() < 0) return 0;

	return 1;
}



void Scene::draw() {
	for (auto it : asteroids) {
		it.draw();
	}
	for (auto it : bullets) {
		it.draw();
	}
	ship.draw();
}


