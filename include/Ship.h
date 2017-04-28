#ifndef SHIP_INCLUDED
#define SHIP_INCLUDED

#include "Drawable.h"
#include "Kinematic.h"
#include "Polygon.h"
#include "Bullet.h"

#define SHIP_MAX_SPEED 5.0
#define SPEED_DECREMENT 0.95

class Ship : public Drawable, public Kinematic, public Polygon {
	private:
		/* angle of rotation in degrees
		 * 	0 = East
		 * 	90 = North
		 * 	180 = West
		 * 	270 = South
		 */
		double rotation;

		unsigned int height;
		unsigned int width;

		double acceleration;

		Color color;

	public:
		static unsigned int DEFAULT_WIDTH;
		static unsigned int DEFAULT_HEIGHT;
		
		Ship (double rotation, const Point& pos);
		Ship (const Ship& ship);

		Bullet shoot();

		void setColor (const Color& color);
		Color getColor() const;

		void setWidth (unsigned int width);
		unsigned int getWidth() const;

		void setHeight (unsigned int height);
		unsigned int getHeight() const;

		void rotate (double angle);
		void setRotation (double angle);
		double getRotation() const;

		void accelerate (double ammount);
		void setAcceleration (double accel);
		double getAcceleration() const;

		Point getCircumcenter() const;

		virtual void createShape() override;
		virtual void move() override;
		virtual void draw() override;

};

#endif
