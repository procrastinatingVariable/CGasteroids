#include <sstream>
#include "Drawable.h"


Drawable::Drawable() : vertices(), color() {
	setLineWidth(1.0);
	setPointSize(1.0);

	setSmoothPoints();
	unfill();
}

Drawable::Drawable (const std::vector<Point>& vertices) : vertices(vertices), color() {
	setLineWidth(1.0);
	setPointSize(1.0);

	setSmoothPoints();
	unfill();
}

Drawable::Drawable (Point* vArray, int num) : vertices(vArray, vArray + num),
																							color() {
	setLineWidth(1.0);
	setPointSize(1.0);

	setSmoothPoints();
	unfill();
}

Drawable::Drawable (const Drawable& d) : vertices(d.getVertices()), color() {
	setLineWidth(d.getLineWidth());
	setPointSize(d.getPointSize());

	smoothPoints = d.smoothPoints;
	filled = d.filled;
}



void Drawable::pushVertex (const Point& v) {
	vertices.push_back(v);
}

void Drawable::pushVertex (double x, double y, double z) {
	pushVertex(Point(x, y, z));
}



Point Drawable::popVertex() {
	Point a(vertices.back());
	vertices.pop_back();
	return a;
}



void Drawable::insertVertex (const Point& v, int pos) {
	auto i = vertices.begin() + pos;
	vertices.insert(i, v);
}

void Drawable::insertVertex (double x, double y, double z, int pos) {
	insertVertex(Point(x, y, z), pos);
}

std::vector<Point> Drawable::getVertices() const {
	return vertices;
}



void Drawable::setColor (const Color& color) {
	this->color = color;
}

Color Drawable::getColor() const {
	return color;
}



void Drawable::setLineWidth (double width) {
	this->lineWidth = width;
}

double Drawable::getLineWidth() const {
	return lineWidth;
}



void Drawable::setPointSize (double size) {
	this->pointSize = size;
}

double Drawable::getPointSize() const {
	return pointSize;
}



void Drawable::setSmoothPoints() {
	smoothPoints = 1;
}

void Drawable::setRuggedPoints() {
	smoothPoints = 0;
}

bool Drawable::isPointSmooth() const {
	return smoothPoints;
}



void Drawable::fill() {
	filled = 1;
}

void Drawable::unfill() {
	filled = 0;
}

bool Drawable::isFilled() const {
	return filled;
}



std::string Drawable::toString() {
	std::ostringstream oString;

	oString << "Vertices : ";
	for (auto i : vertices) {
		oString << '(' << i.getX() << ',' << i.getY() << ',' << i.getZ() << ") ";
	}
	oString << std::endl;
	oString << "lineWidth: " << lineWidth << std::endl;
	oString << "pointSize: " << pointSize << std::endl;
	oString << "smoothPoints: " << (smoothPoints ? "TRUE" : "FALSE") << std::endl;
	oString << "filled: " << (filled == 1 ? "TRUE" :  "FALSE") << std::endl;
	oString << std::endl;

	return oString.str();
}
