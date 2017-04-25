#ifndef POINT_INCLUDED
#define POINT_INCLUDED

class Point {
	private:
		float x;
		float y;
		float z;
		
	public:
		Point();
		Point(float x, float y, float z = 0.0);
		Point(const Point& p);

		float* get2DPointArray() const;
		float* get3DPointArray() const;

		void setX(float value);
		float getX() const;

		void setY(float value);
		float getY() const;

		void setZ(float value);
		float getZ() const;

		void scale (float value);

		Point& operator=(const Point& p);
		friend Point operator* (float c, const Point& p);


};

#endif
