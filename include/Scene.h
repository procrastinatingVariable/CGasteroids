#ifndef SCENE_INCLUDED
#define SCENE_INCLUDED

#include <list>
#include "Asteroid.h"
#include "Color.h"

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b

class Scene {
	private:
		static const float SMALL_ASTEROID_PERCENT;
		static const float MEDIUM_ASTEROID_PERCENT;
		static const float LARGE_ASTEROID_PERCENT;

		std::list<Asteroid> actors;

		unsigned int sceneWidth;
		unsigned int sceneHeight;

		unsigned int animationDelay; //in millis

		unsigned int smallAsteroidRadius;
		unsigned int mediumAsteroidRadius;
		unsigned int largeAsteroidRadius;

		Color background;

		int getRandomIntBetween (int min, int max);
		float getRandomFloatBetween (float min, float max);
		Vector getRandomVelocity (float minSpeed, float maxSpeed);

		void computeAsteroidSizes();

		Point wrapAroundView (Point p);


	public:
		Scene();
		Scene (unsigned int width, 
					 unsigned int height,
					 unsigned int animDelay,
					 Color bkg);
		Scene (const Scene& s);

		void advanceAnimation();

		void addAsteroid(const Asteroid& a);
		void generateAsteroids (int count);
		const std::list<Asteroid>& getAsteroids() const;

		void setWidth (unsigned int width);
		unsigned int getWidth() const;

		void setHeight (unsigned int height);
		unsigned int getHeight() const;

		void setAnimationDelay (unsigned int delay);
		unsigned int getAnimationDelay() const;

		void setBackground (Color c);
		Color getBackground() const;

		Scene& operator= (Scene& s);


};


#endif
