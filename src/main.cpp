#include <iostream>
#include <GL/freeglut.h>

#include "Point.h"
#include "Vector.h"
#include "Color.h"
#include "Drawable.h"
#include "Asteroid.h"
#include "Scene.h"
#include "Ship.h"
#include "Bullet.h"

using namespace std;

Scene game(600, 600, 1000/60, Color());

void drawCRTEffect() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLineWidth(3);

	int sceneHeight = game.getHeight();
	int sceneWidth = game.getWidth();
	int lineY;

	glColor4f(0.22, 0.26, 0.31, 0.4);

	glBegin(GL_LINES);

		for (int i = 0; i < sceneHeight; i+= 6) {

			if ( (i/6) % 2 == 0) 
				lineY = i - 3;
			else 
				lineY = i;

			glVertex2f(0.0, lineY);
			glVertex2f(sceneWidth, lineY);
			
		}

	glEnd();

	glDisable(GL_BLEND);
}


void control(int key, int x, int y) {
	static Ship& mainShip = game.getShip();

	switch (key) {
		case GLUT_KEY_UP:
				mainShip.setAcceleration(0.5);
			break;

		case GLUT_KEY_LEFT:
				mainShip.rotate(-5.0);
			break;

		case GLUT_KEY_DOWN:
				mainShip.setAcceleration(0.0);
			break;

		case GLUT_KEY_RIGHT:
				mainShip.rotate(5.0);
			break;

		default:
			break;
	}

}

void control2 (unsigned char key, int x, int y) {
	if (key == ' ') {
		Bullet b = game.getShip().shoot();
		game.addBullet(b);
	}
}




void clock(int value) {
	game.advanceAnimation();
	glutPostRedisplay();
	glutTimerFunc(game.getAnimationDelay(), clock, 0);
}

void draw() {
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	game.draw();
	drawCRTEffect();

	glutSwapBuffers();
	glFlush();
}

int main(int nargs, char* args[]) {
	
	game.generateAsteroids(10);


	glutInit(&nargs, args);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
	glutCreateWindow("test");

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, game.getWidth(), 0, game.getHeight());


	glutKeyboardFunc(control2);
	glutSpecialFunc(control);
	glutTimerFunc(game.getAnimationDelay(), clock, 0);
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
