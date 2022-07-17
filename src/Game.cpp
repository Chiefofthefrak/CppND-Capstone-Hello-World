
#include <iostream>
#include <vector>
#include <thread>
#include <iterator>
#include <algorithm>
#include <cmath>

#include <SDL2/SDL.h>

#include "Game.h"
#include "OrbitObject.h"

Game::Game(int screenwidth, int screenheight): screenwidth(screenwidth), screenheight(screenheight)
{ 


	//Make 3 New Asteroids and a Target and Player object with specified sizes and put them in the vector orbitPointers

	orbitPointers.push_back(std::make_shared<OrbitObject>(15, asteroid, screenwidth/4, 0,0,1.7));
	orbitPointers.push_back(std::make_shared<OrbitObject>(30, asteroid,-screenwidth/3, 0,0,-1.4));
	orbitPointers.push_back(std::make_shared<OrbitObject>(40, asteroid,3*screenwidth/4, 0,0,0.95));

	orbitPointers.push_back(std::make_shared<OrbitObject>(20, target, -screenwidth/2, 0,0,-1.2));
	orbitPointers.push_back(std::make_shared<OrbitObject>(20, player, screenwidth/3, 0,0,1.45));


}

void Game::Update(){

	int mouseX, mouseY;
	bool mousePressed = false;

	readInput(mouseX, mouseY, mousePressed);
	if (mousePressed){
		lightFired = true;

	}

	for(auto &orbitItem : orbitPointers){ //Loop thru vector of pointers to orbitObjects and run orbit on each
		orbitItem->Orbit();
	}


    if(LightFired()){ //TODO: Update Light Position
    	if(mousePressed and lightPointers.size() <= 20){
    		//Find direction to mouse position from player position
    		double orbitPosX, orbitPosY;
    		orbitPointers.back()->getPosition(orbitPosX,orbitPosY);
    		double dy = (1.0*mouseY - orbitPosY);
    		double dx = (1.0*mouseX - orbitPosX);
    		auto total =  std::sqrt( dx*dx + dy*dy);


    		//Add lightray to light pointers and Orbit in direction of mouse at 8 units total speed from surface of player
    		lightPointers.push_back(std::make_shared<LightRay>(2,light,orbitPosX+(dx/(total))*20,orbitPosY + (dy/(total))*20, (dx/(total))*8,(dy/(total))*8));
    	}
    	int lightPointerNumber = 0;
    	for(auto &ray : lightPointers){ //Loop thru vector of pointers to lightRays and run orbit and collisioncheck
			ray->Orbit();

			double rayX,rayY; 
			ray->getPosition(rayX,rayY);
			if(std::sqrt(rayX*rayX + rayY*rayY) <= screenwidth/8){ //Absorb if collided with BH
				ray->absorb();
			}

			for (auto &orbitItem : orbitPointers){
				if (ray->collisionCheck(*orbitItem)){ //Check if ray collided with any orbitItem and do something depending on what type they are
					switch (orbitItem->getType()){	
						case player:

						case target:
							Win();
						case asteroid://ray is absorbed by asteroid
							ray->absorb();
							std::cout << " Ray absorbed " << std::endl;					
						} 
				}
			}
			lightPointerNumber++;
		}

    }
}
void Game::readInput(int &mouseX, int &mouseY, bool &mousePressed){ //Track Mouse and determine when left mouse is pressed

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

std::vector<std::shared_ptr<LightRay>> Game::getLightRay(){ //Returns the vector of pointers to LightRays
	return lightPointers;
}


void Game::Win(){
	running = false;

}
bool Game::Running(){
	return running;
}