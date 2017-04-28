#ifndef MOVABLE_INCLUDED
#define MOVABLE_INCLUDED

#include <string>
#include "Vector.h"

class Kinematic {
	private:
		Vector velocity;
		Point position;
		
	public:
		Kinematic();
		Kinematic (const Point& p);
		Kinematic (const Point& p, const Vector& v);
		Kinematic (const Kinematic& k);

		Point getPosition() const;
		void setPosition (const Point& pos);

		Vector getVelocity() const;
		void setVelocity (const Vector& v);

		double getSpeed() const;
		// changes the magnitued of the velocity vector
		void setSpeed (double speed);
		// keeps the speed constant, but changes the direction as to point to p
		void setDirection (const Point& p);

		virtual void move() = 0;

		std::string toString();

};

#endif
