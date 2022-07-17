# CPPND: Capstone Hello World Repo

This is a project repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

In this project, I have built my own C++ application starting with the Hello World repo. 

## Dependencies for Running Locally

* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 

## Basic Build Instructions

1. Clone this repo.
2. Move to the build directory `cd build`
3. Compile: `cmake .. && make`
4. Run it: `./OrbitGame`.

##Expected Behaviour

When run, a window will pop up with a blue background and a black circle in the middle, this is the central Black hole (BH) mentioned in comments.
There will also be 3 grey asteroids, a red target and a blue player.
These will all orbit the black hole using the Orbit function.
When the user clicks their mouse, a purple projectile will shoot from the player object in the direction of the mouse up to 20 times.
The projectile will be absorbed if it collides with an asteroid or the black hole, and will cause a message saying "you win!" if it collides with the target, followed by the application closing.
There is a time-limit of 2 minutes on the application after which it will close.

## Code Structure

Ths src directory contains all of the .h and .cpp files necessary to run the project.

* main.cpp contains the main function and the game loop with time control.

* Game.cpp and Game.h contain the Game class which has the function Update which updates the gamestate, and readInput which reads the mouse state.

* Display.cpp and Diplay.h contain the Display class which has the function Render which renders the game state to the screen, as well as some functions to make this easier.

* OrbitObject.cpp and OrbitObject.h have the classes OrbitObject and LightRay which control how asteroids, target and player, and the projectile behave respectively. Both contain the function Orbit which updates the positions and velocities of the objects as well as various other functions.

## Rubric Information

The project demonstrates a variety of control structures: eg in Game.cpp lines 30, 36, 41, 71 etc or anywhere in the code.

The project accepts user input and processes the input: eg in Game::readInput Game.cpp line 90.

The project uses object oriented programming: Game, OrbitObject, LightRay and Diplay classes in their respective .h files.

Classes use appropriate access specifiers: Game, OrbitObject, LightRay and Diplay classes all specify member variables and functions and public, protected or private.

Class constructors use member initialization lists: OrbitObject.cpp lines 33 and 69, Display.cpp line 11, Game.cpp line 14

Classes abstract implementation details from their interfaces: All functions in all 4 classes

Classes encapsulate behavior.

The project makes use of references in function declarations: eg OrbitObjecth lines 26, 29, 66, 69, 72 or Game.h line 24

The project uses smart pointers instead of raw pointers: Game.h lines 17, 18, 37 and 38 Game.cpp lines 20-25, 57 etc
