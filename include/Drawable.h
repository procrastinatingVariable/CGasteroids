#ifndef DRAWABLE_INCLUDED
#define DRAWABLE_INCLUDED

#include <vector>

#include "Point.h"

// class that models any entity (asteroid and ship) that will be drawn

class Drawable {
	private:
		vector<Point> vertices;
		float lineThicknes;
		bool filledState;
		Color rgbColor;
		
	public:
		Drawable();
		Drawable(vector<Point>& vertices,
						 float lineThickness,
						 bool isFilled,
						 Color& rgbColor);
		
		// vertices operations
		Point getVertex(int vertexIndex);
		void addVertex(Point newVertex);

		// lineThickness operations
		float getLineThickness();
		void setLineThickness(float lineThickness);

		// isFilled operations
		bool isFilled();
		void setFilledState(bool filledState);

		// rgbColor operations
		Color getColor();
		void setColor(Color& rgbColor);

		virtual ~Drawable() = 0;

}

#endif
