#ifndef POINT_INCLUDED
#define POINT_INCLUDED


class Point {
	private:
		float x;
		float y;
		float z;

	public:
		Point() = default;
		Point(float x, float y, float z = 0.0);

		// x component
		float getX();
		void setX(float x);

		// y component
		float getY();
		void setY(float y);

		// z component
		float getZ();
		void setZ(float z);

		// 2D array getter
		float* get2DArray();

		// 3D array getter
		float* get3DArray();

		// operator= overload
		Point& operator=(Point& src);


}

#endif
