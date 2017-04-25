#ifndef VECTOR_INCLUDED
#define VECTOR_INCLUDED

#include "Point.h"

#define PI 3.1415926535897
#define MATH_RADIANS(angle) angle / 180.0 * PI

// models a vector that's centered at the origin
class Vector {
	private:
		Point endPoint;

	public:
		Vector();
		Vector (const Point& endPoint);
		Vector (float x, float y, float z = 0.0);
		Vector (const Vector& v);

		void setXComponent (float x);
		float getXComponent() const;

		void setYComponent (float y);
		float getYComponent() const;

		void setZComponent (float z);
		float getZComponent() const;

		void setEndPoint (const Point& endPoint);
		Point getEndPoint() const;

		float getMagnitude() const;

		Vector& operator= (const Vector& v);
		friend Vector operator+ (const Vector& a, const Vector& b);
		friend Vector operator* (float scalar, const Vector& a);
		Vector crossProduct (const Vector& v);

		Vector getUnitVector() const;

		// rotates the vector around the origin
		// positive angle rotates CCW
		Vector rotate2D (float angle);

};

#endif
