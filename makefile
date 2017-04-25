VPATH = src:include
libs = -lGL -lGLU -lglut
includes = -Iinclude
prereq = Asteroid.h Color.h Drawable.h \
			   Movable.h Point.h Vector.h Scene.h ScenePainter.h\
				 main.cpp Point.cpp Vector.cpp Color.cpp Drawable.cpp Movable.cpp \
				 Asteroid.cpp Scene.cpp ScenePainter.cpp
main : $(prereq)
	g++ $(libs) $(includes) -o main src/*.cpp

	
