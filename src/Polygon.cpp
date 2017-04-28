#include "Polygon.h"

Polygon::Polygon() : vertices() {
	setLineWidth(1);
	unfill();
}

Polygon::Polygon (const std::vector<Point>& vertices) : vertices(vertices) {
	setLineWidth(1);
	unfill();
}

Polygon::Polygon (Point* vArray, int num) : vertices(vArray, vArray + num) {
	setLineWidth(1);
	unfill();
}

Polygon::Polygon (const Polygon& p) : Polygon (p.getVertices()) {
}



void Polygon::pushVertex (const Point& v) {
	vertices.push_back(v);
}

Point Polygon::popVertex() {
	Point a(vertices.back());
	vertices.pop_back();

	return a;
}

void Polygon::insertVertex (const Point& v, int pos) {
	auto i = vertices.begin() + pos;
	vertices.insert(i, v);
}

std::vector<Point> Polygon::getVertices() const {
	return vertices;
}



void Polygon::setLineWidth (double width) {
	lineWidth = width >= 0 ? width : 0.0;
}

double Polygon::getLineWidth() {
	return lineWidth;
}



void Polygon::fill() {
	filled = 1;
}

void Polygon::unfill() {
	filled = 0;
}

bool Polygon::isFilled() const {
	return filled;
}

