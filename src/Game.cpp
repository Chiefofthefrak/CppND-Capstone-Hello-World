
#include <iostream>
#include <vector>
#include <thread>
#include <iterator>
#include <algorithm>
#include <cmath>

#include <SDL2/SDL.h>

#include "Game.h"
#include "OrbitObject.h"

Game::Game(int screenwidth, int screenheight){ 


	//Make 3 New Asteroids and a Target and Player object with specified sizes and put them in the vector orbitPointers

	orbitPointers.push_back(std::make_shared<OrbitObject>(10, asteroid, screenwidth/4, 0,1,100));
	orbitPointers.push_back(std::make_shared<OrbitObject>(30, asteroid,-screenwidth/3, 0,2,130));
	orbitPointers.push_back(std::make_shared<OrbitObject>(50, asteroid,3*screenwidth/4, 0,1,110));

	orbitPointers.push_back(std::make_shared<OrbitObject>(20, target, -screenwidth/2, 0,1,120));
	orbitPointers.push_back(std::make_shared<OrbitObject>(20, player, screenwidth/3, 0,1,80));


}
/*Game::~Game(){
	    // set up thread barrier before this object is destroyed
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
}*/


void Game::Update(){

	int mouseX, mouseY;
	bool mousePressed;

	readInput(mouseX, mouseY, mousePressed);
	if (mousePressed){
		lightFired = true;

	}

	for(auto &orbitItem : orbitPointers){ //Loop thru vector of pointers to orbitObjects and run orbit on each
		orbitItem->Orbit();
		//threads.emplace_back(&OrbitObject::Orbit, orbitItem); 
	}

   /* std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
    std::cout << "Threads empty? " << threads.empty() << std::endl;*/

    if(LightFired()){ //TODO: Update Light Position
    	if(lightPointers.empty()){
    		//Find direction to mouse position from player position
    		double orbitPosX, orbitPosY;
    		orbitPointers.back()->getPosition(orbitPosX,orbitPosY);
    		double dy = (orbitPosY - 1.0*mouseY);
    		double dx = (orbitPosX - 1.0*mouseX)
    		auto gradient =  dy/dx;


    		//Add lightray to light pointers and Orbit in direction of mouse at 500 units total speed
    		lightPointers.push_back(std::make_shared<LightRay>(3,light,orbitPosX,orbitPosY, (500/std::abs(gradient))*dx,(500/std::abs(gradient))*dy));
    	}
    	for(auto &ray : lightPointers){ //Loop thru vector of pointers to lightRays and run orbit on each
			ray->Orbit();
		
		}

    }
}
void Game::readInput(int &mouseX, int &mouseY, bool &mousePressed){ //Track Mouse and determine when it's pressed

	SDL_PumpEvents();  // make sure we have the latest mouse state.
	auto buttons = SDL_GetMouseState(&mouseX, &mouseY);

	if ((buttons & SDL_BUTTON_LMASK) != 0) {
		mousePressed = true;
	}	

}

bool Game::LightFired(){ //Returns whether the light has been fired
	return lightFired;
}


std::vector<std::shared_ptr<OrbitObject>> Game::getOrbiters(){ //Returns the vector of pointers to all OrbitObjects in the game
	return orbitPointers;
}