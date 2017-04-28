#ifndef POINT_INCLUDED
#define POINT_INCLUDED

class Point {
	private:
		double x;
		double y;
		double z;
		
	public:
		Point();
		Point(double x, double y, double z = 0.0);
		Point(const Point& p);

		void get2DPointArray (double array[2]) const;
		void get3DPointArray (double array[3]) const;

		void setX(double value);
		double getX() const;

		void setY(double value);
		double getY() const;

		void setZ(double value);
		double getZ() const;

		void scale (double value);

		Point& operator=(const Point& p);
		friend Point operator* (double c, const Point& p);

		static double distance(const Point& a, const Point& b);

};

#endif
