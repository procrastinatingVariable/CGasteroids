#include <iostream>
#include "ScenePainter.h"


Scene ScenePainter::stage = Scene();
void ScenePainter::attachScene (Scene s) {
	stage = s;
}

const Scene& ScenePainter::getScene() {
	return stage;
}



void ScenePainter::setViewport (const Scene& s) {
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, s.getWidth(), 0, s.getHeight());
}



void ScenePainter::drawAsteroid (const Asteroid& a) {
	glColor3dv(a.getColor().getRGBDoubleArray());
	glLineWidth(a.getLineWidth());
	if (!a.isFilled())
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	

	glPushMatrix();
	glTranslatef( a.getPosition().getX(), 
							  a.getPosition().getY(), 
							  a.getPosition().getZ() );

	glBegin(GL_POLYGON);

		for (auto v : a.getVertices()) {
			glVertex2fv(v.get2DPointArray());
		}

	glEnd();
	glPopMatrix();
}


bool ScenePainter::painterInitialized = 0;
void ScenePainter::initPainter (const Scene& s) {
	if (painterInitialized == 1) return;

	painterInitialized = 1;

	attachScene(s);
 
	int dummyNargs = 1;
	char* dummyArgv[1];
	glutInit(&dummyNargs, dummyArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
}



void ScenePainter::createWindow (Point position,
																 std::string title) {
	int width = stage.getWidth();
	int height = stage.getHeight();

	glutInitWindowSize(width, height);
	glutInitWindowPosition(position.getX(), position.getY());
	glutCreateWindow(title.c_str());

	glutDisplayFunc(drawScene);
	glutTimerFunc(stage.getAnimationDelay(), animateScene, 0);

	setViewport(stage);
}



void ScenePainter::animateScene(int callbackValue) {
	stage.advanceAnimation();
	glutPostRedisplay();
	glutTimerFunc(stage.getAnimationDelay(), animateScene, callbackValue);
}



void ScenePainter::drawScene () {
	glClearColor(stage.getBackground().getDRed(),
							 stage.getBackground().getDGreen(),
							 stage.getBackground().getDBlue(),
							 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	static const std::list<Asteroid>& asteroids = stage.getAsteroids();
	for (auto v : asteroids) {
		drawAsteroid(v);
	}

	glutSwapBuffers();
	glFlush();
}



void ScenePainter::startScene() {
	glutMainLoop();
}
