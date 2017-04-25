#ifndef DRAWABLE_INCLUDED
#define DRAWABLE_INCLUDED

#include <vector>
#include <string>
#include "Point.h"
#include "Color.h"


class Drawable {
	protected:
		std::vector<Point> vertices;

	private:
		Color color;
		double lineWidth;
		double pointSize;
		
		bool smoothPoints;
		bool filled;

	public: 
		Drawable();
		Drawable(const std::vector<Point>& vertices);
		Drawable(Point* vArray, int num);
		Drawable(const Drawable& d);

		void pushVertex(const Point& v);
		void pushVertex(double x, double y, double z);

		Point popVertex();

		void insertVertex(const Point& v, int pos);
		void insertVertex(double x, double y, double z, int pos);

		std::vector<Point> getVertices() const;
		
		// each subclass will define its shape
		virtual void generateVertices() = 0;


		void setColor(const Color& color);
		Color getColor() const;

		void setLineWidth(double width);
		double getLineWidth() const;

		void setPointSize(double size);
		double getPointSize() const;

		void setSmoothPoints();
		void setRuggedPoints();
		bool isPointSmooth() const;

		void fill();
		void unfill();
		bool isFilled() const;

		std::string toString();

};

#endif
