#ifndef SCENE_PAINTER_INCLUDED
#define SCENE_PAINTER_INCLUDED

#include "Scene.h"
#include <string>
#include <GL/freeglut.h>

class ScenePainter {
	private:
		static Scene stage;
		static bool painterInitialized;

		static void setViewport (const Scene& s);
		static void attachScene (Scene s);

		static void drawAsteroid (const Asteroid& a);

	public:
		static const Scene& getScene();

		// must be called before any drawing operations are performed
		static void initPainter (const Scene& s);

		static void createWindow (Point position,
															std::string title);

		// callback for animating based on velocities and user input
		static void animateScene (int callbackValue);
		// callback for drawing the elements of the scene
		static void drawScene();
		// start the main event loop
		static void startScene();

};



#endif
