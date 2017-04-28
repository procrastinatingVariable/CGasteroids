#ifndef ASTEROID_INCLUDED
#define ASTEROID_INCLUDED

#include "Polygon.h"
#include "Kinematic.h"
#include "Drawable.h"
#include "Ship.h"

#define ASTEROID_MIN_SPEED 1.0
#define ASTEROID_MAX_SPEED 3.0

class Asteroid : public Polygon, public Kinematic, public Drawable {
	private:
		// radius of the size of the octagon from which the shape is derived
		double size;

		Color color;

		int getRandomIntBetween (int min, int max);
		double getRandomFloatBetween (double min, double max);

	public:
		static unsigned int SIZE_SMALL;
		static unsigned int SIZE_MEDIUM;
		static unsigned int SIZE_BIG;

		Asteroid();
		Asteroid (double size, const Point& pos);
		Asteroid (double size, const Point& pos, const Vector& vel);

		bool hasCollided(const Ship& s);
		bool hasCollided(const Bullet& b);

		void setColor (const Color& color);
		Color getColor() const;

		void setSize (double size);
		double getSize() const;

		virtual void createShape() override;
		virtual void move() override;
		virtual void draw() override;

};

#endif
