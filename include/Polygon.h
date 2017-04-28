#ifndef POLYGON_INCLUDED
#define POLYGON_INCLUDED

#include <string>
#include <vector>
#include "Point.h"
#include "Color.h"

class Polygon {
	protected:
		std::vector<Point> vertices;

	private:
		double lineWidth;

		bool filled;

	public:
		Polygon();
		Polygon (const std::vector<Point>& vertices);
		Polygon (Point* vArray, int num);
		Polygon (const Polygon& p);
		
		void pushVertex (const Point& v);
		Point popVertex();
		void insertVertex (const Point& v, int pos);
		std::vector<Point> getVertices() const;

		void setLineWidth (double width);
		double getLineWidth();

		void fill();
		void unfill();
		bool isFilled() const;

		// each shape will define its own vertices
		virtual void createShape() = 0;

};


#endif
