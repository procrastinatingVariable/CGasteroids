#ifndef ASTEROID_INCLUDED
#define ASTEROID_INCLUDED

#include "Movable.h"
#include "Drawable.h"

class Asteroid : public Movable, public Drawable {
	private:
		// radius of the size of the octagon from which the shape is derived
		float size;

		int getRandomIntBetween (int min, int max);
		float getRandomFloatBetween (float min, float max);

	public:
		Asteroid();
		Asteroid (float size, 
							const Point& position, 
							const Vector& velocity);

		void setSize (float size);
		float getSize() const;

		virtual void generateVertices() override;
		virtual void move() override;

};

#endif
