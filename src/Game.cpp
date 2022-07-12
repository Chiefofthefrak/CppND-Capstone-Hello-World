
#include <iostream>
#include <vector>
#include <thread>
#include <iterator>
#include <algorithm>

#include <SDL2/SDL.h>

#include "Game.h"
#include "OrbitObject.h"

Game::Game(){ 


	//Make 3 New Asteroids and a Target and Player object with specified sizes and put them in the vector orbitPointers

	orbitPointers.push_back(std::make_shared<OrbitObject>(10, asteroid,50,50,10,10));
	orbitPointers.push_back(std::make_shared<OrbitObject>(30, asteroid,100,100,15,15));
	orbitPointers.push_back(std::make_shared<OrbitObject>(50, asteroid,-50,-50,10,10));

	orbitPointers.push_back(std::make_shared<OrbitObject>(20, target,-100,-100,15,15));
	orbitPointers.push_back(std::make_shared<OrbitObject>(20, player,200,200,15,15));


}
Game::~Game(){
	    // set up thread barrier before this object is destroyed
    /*std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });*/
}


void Game::Update(){

	int mouseX, mouseY;
	bool mousePressed;

	readInput(mouseX, mouseY, mousePressed);
	if (mousePressed == true){
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