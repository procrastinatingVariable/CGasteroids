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

	- **Polygon** stores the data that **defines** the **shape** of the actors :
	**Ship** and **Asteroid**

	- **Drawable** acts as an **interface** (from Java), that contains a method
	**draw**, which the **implementing classes** need to **define** if they want
	to be drawn on the screen.

* **Asteroid**, **Ship** and **Projectile** are the main **actors** of the game.

	- The shape of the **asteroids** is generated randomly by adding two random
	vertices to a **octagon**

	- Both **asteroids** and the **ship** have their shape defined in **MODEL SPACE**
	(relative to the origin of the **WORLD SPACE**)

	- All **Kinematics** are positioned in the **scene** using a **translation transform** to
	their **position attribute**.

	- The **ship's rotation** is added in the same manner using a **rotation transform**

	- The **Asteroid** class also implements a method that checks for **collisions**
	with other objects. It does that by checking if the **center** of the **object**
	is closer to the **center of the asteroid** than the **asteroid's radius**.

* The **Scene** class is where all the physics and game logic are processsed. It
implements an *advanceScene* method that determines the positions and collisions
between the actors.

* The **game logic** and **physics** are independent from the **graphics**
(they **don't** depend on the framerate). This is achieved by using *glIdleFunc*,
where the **scene's** *advanceScene()* method is called. The **scene** is drawn
in the display function where its *draw()* method is called.



