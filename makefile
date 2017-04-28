VPATH = src:include:obj
gl_libs = -lGL -lGLU -lglut
obj_depend = obj/scene.o obj/asteroid.o obj/kinematic.o obj/polygon.o obj/vector.o obj/polygon.o obj/color.o

header_prereq = Asteroid.h Drawable.h Point.h Scene.h Color.h Kinematic.h Polygon.h Vector.h Ship.h Bullet.h
source_prereq = main.cpp Asteroid.cpp Point.cpp Scene.cpp Color.cpp Kinematic.cpp Polygon.cpp Vector.cpp Ship.cpp Bullet.cpp

main : $(header_prereq) $(source_prereq)
	g++ -Wall  $(gl_libs) -Iinclude -o main src/main.cpp src/Asteroid.cpp src/Point.cpp src/Scene.cpp src/Color.cpp src/Kinematic.cpp src/Polygon.cpp src/Vector.cpp src/Ship.cpp src/Bullet.cpp

# main : scene.o
# 	g++ $(gl_libs) -Iinclude -Lobj -o main src/main.cpp $(obj_depend)
# 
# scene.o : Scene.h Scene.cpp asteroid.o
# 	g++ -c $(gl_libs) -Iinclude -Lobj -lasteroid.o -o obj/scene.o src/Scene.cpp
# 
# asteroid.o : Asteroid.h Asteroid.cpp kinematic.o polygon.o
# 	g++ -c $(gl_libs) -Iinclude -Lobj -lkinematic.o -lpolygon.o -o obj/asteroid.o src/Asteroid.cpp
# 
# kinematic.o : Kinematic.h Kinematic.cpp vector.o point.o
# 	g++ -c -Iinclude -Lobj -lvector.o -lpoint.o -o obj/kinematic.o src/Kinematic.cpp
# 
# polygon.o : Polygon.h Polygon.cpp point.o
# 	g++ -c -Iinclude -Lobj -lpoint.o -o obj/polygon.o src/Polygon.cpp
# 
# vector.o : Vector.h Vector.cpp point.o
# 	g++ -c -Iinclude -Lobj -lpoint.o -o obj/vector.o src/Vector.cpp
# 
# point.o : Point.h Point.cpp
# 	g++ -c -Iinclude -o obj/point.o src/Point.cpp
# 
# color.o : Color.h Color.cpp
# 	g++ -c -Iinclude -o obj/color.o src/Color.cpp




