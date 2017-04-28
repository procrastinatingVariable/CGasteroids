ASTEROIDS CLONE
===============


Feature Specification
---------------------
* Keyboard controls
	- LEFT, RIGHT -> rotation
	- UP, DOWN -> movement
	- SPACE -> fire

* Basic physics
	- velocity
	- acceleration

* Primitive based graphics
	- lines
	- points

* Circular scene (wraps around the edges)


Scenario
--------
	The game start **immediately**. A **random** number of **asteroids** 
will be **generated** with **different valocities**. They will **move** in
a **straight line** until they get **destroyed** by **colliding** with a 
**projectile**.
	
	The player starts off **in the middle** of the scene as a **triangle** 
shapped ship. The **left arrow key** will rotate the ship **counterclockwise**,
while the **right arrow key** will rotate it **clockwise**. Pressing the 
**up arrow key** will make the ship **accelerate** at a **steady pace**
until it reaches its **max velocity**. Pressing the **down arrow key** will
**stop** the acceleration, making the ship **drecrease** its speed at a steady
rate, untill it reaches a **minimum** speed.

	When either an **asteroid** or the **player** pass the **edge** of the 
**scene**, they will **loop around** on the **diametrically opposite** side
of the scene.

	When the player presses the **space key** the **ship** will **shoot** a
**projectile** at a **fixed speed** in the direction the ship **is facing**.
The **bullet** will travel until it **collides** with an asteroid or it
**leaves** the **scene** (it will **NOT** loop around).


Technicalities
--------------

	* There are 3 main classes that provide the needed behaviour for the ship,
asteroids and projectiles : **Kinematic**, **Drawable** and **Polygon**
		- **Kinematic** models an object which has a position and a velocity:
			The **position** is a **POINT** in 2D space while the **velocity** is a
			**mathematical VECTOR** which has an **X component** and a **Y component**.

			The **speed** of any Kinematic can be found by computing its **velocity
			vector's magnitude**.

	* 
