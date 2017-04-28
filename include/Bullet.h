#ifndef BULLET_INCLUDED
#define BULLET_INCLUDED

#include "Drawable.h"
#include "Kinematic.h"
#include "Color.h"

class Bullet : public Kinematic, public Drawable{
	private:
		Color color;
		double size;

	public:
		Bullet();
		Bullet(double size, const Point& pos, const Vector& vel);

		void setColor (const Color& color);
		Color getColor() const;

		void setSize (double size);
		double getSize () const;

		virtual void draw() override;
		virtual void move() override;

};


#endif
