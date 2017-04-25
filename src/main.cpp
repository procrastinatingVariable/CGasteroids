#include <iostream>

#include "Point.h"
#include "Vector.h"
#include "Color.h"
#include "Drawable.h"
#include "Asteroid.h"
#include "Scene.h"
#include "ScenePainter.h"

using namespace std;


void testScenePainter() {
	Scene s(600, 600, 17, Color(0.0, 0.0, 0.2));
	s.generateAsteroids(100);

	ScenePainter::initPainter(s);
	ScenePainter::createWindow(Point(100, 100), "test");
	ScenePainter::startScene();
}

int main() {
	testScenePainter();

	return 0;
}
