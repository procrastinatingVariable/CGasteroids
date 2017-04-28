#ifndef SCENE_INCLUDED
#define SCENE_INCLUDED

#include <list>
#include "Asteroid.h"
#include "Color.h"
#include "Drawable.h"
#include "Ship.h"
#include "Bullet.h"

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b

class Scene : public Drawable{
	private:
		std::list<Asteroid> asteroids;
		std::list<Bullet> bullets;
		Ship ship;

		unsigned int sceneWidth;
		unsigned int sceneHeight;

		unsigned int animationDelay; //in millis

		Color background;

		int getRandomIntBetween (int min, int max);
		float getRandomFloatBetween (float min, float max);
		Vector getRandomVelocity (float minSpeed, float maxSpeed);

		Point wrapAroundView (Point p);

	public:
		Scene();
		Scene (unsigned int width, 
					 unsigned int height,
					 unsigned int animDelay,
					 Color bkg);
		Scene (Scene& s);

		void advanceAnimation();

		void addAsteroid(const Asteroid& a);
		void removeAsteroid(std::list<Asteroid>::iterator it);
		void generateAsteroids (int count);

		void addBullet (const Bullet& b);
		void removeBullet (std::list<Bullet>::iterator it);

		Ship& getShip();

		void setWidth (unsigned int width);
		unsigned int getWidth() const;

		void setHeight (unsigned int height);
		unsigned int getHeight() const;

		void setAnimationDelay (unsigned int delay);
		unsigned int getAnimationDelay() const;

		void setBackground (Color c);
		Color getBackground() const;

		bool isInScene (const Point& p) const;

		virtual void draw() override;

};


#endif
