#ifndef MOVABLE_INCLUDED
#define MOVABLE_INCLUDED

#include <string>
#include "Vector.h"

class Movable {
	private:
		Vector velocity;
		Point position;
		
	public:
		Movable();
		Movable (const Point& p);
		Movable (const Point& p, const Vector& v);

		Point getPosition() const;
		void setPosition (const Point& pos);

		Vector getVelocity() const;
		void setVelocity (const Vector& v);

		float getSpeed() const;
		// changes the magnitued of the velocity vector
		void setSpeed (float speed);
		// keeps the speed constant, but changes the direction as to point to p
		void setDirection (const Point& p);

		virtual void move() = 0;

		std::string toString();

};

#endif
