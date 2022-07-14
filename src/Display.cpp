#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cmath>


#include "Display.h"
#include "OrbitObject.h"
#include "Game.h"

Display::Display(const int p_width, const int p_height) : sdl_window(NULL), sdl_renderer(NULL), p_height(p_height), p_width(p_width)
{
	sdl_window = SDL_CreateWindow("OrbitGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

	if(sdl_window == NULL){
		std::cout << "Window failed to initialise. Error: " << SDL_GetError() << std::endl;
	}

	sdl_renderer = SDL_CreateRenderer(sdl_window,-1, SDL_RENDERER_ACCELERATED);

	if(sdl_renderer == NULL){
		std::cout << "renderer failed to initialise. Error: " << SDL_GetError() << std::endl;
	}

}

Display::~Display(){
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}

void Display::Render(Game game){

	//Clear Screen
	SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00,0x26, 0xFF);
	SDL_RenderClear(sdl_renderer);

	// Render Central BH
	SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00,0x00, 0xFF);
	DrawCircle(p_width/2, p_height/2, p_width/8);

	// Render Orbiters
	auto orbitersToRender = game.getOrbiters();
	double orbiterPosX, orbiterPosY;
	for(auto &Orbiter : orbitersToRender){ //TODO: Change depending on what type of pointer is in orbitPointers
		auto radius = Orbiter->getSize();

		Orbiter->getPosition(orbiterPosX,orbiterPosY);
		orbiterPosX += p_width/2;
		orbiterPosY += p_height/2;
		switch(Orbiter->getType()){
			case ObjectType::player:
				SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x4B,0xFF, 0xFF);
				DrawCircle(orbiterPosX, orbiterPosY, radius);
				break;
			
			case ObjectType::target:
				SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00,0x00, 0xFF);
				DrawCircle(orbiterPosX, orbiterPosY, radius);
				break;
			
			default:
				SDL_SetRenderDrawColor(sdl_renderer, 0xAF, 0xAF,0xAF, 0xFF);
				DrawCircle(orbiterPosX, orbiterPosY, radius);
				break;
			
		}
	}

	// Render Light Ray
	if(game.LightFired()){
		auto rayToRender = game.getLightRay();
		SDL_SetRenderDrawColor(sdl_renderer, 0xAF, 0x00,0x4E, 0xFF);
		for(int i = 0; i<= rayToRender.back()->previousXs.size(); i++ ){ //TODO: Change depending on implementation of LightRay in Game
			DrawCircle(rayToRender.back()->previousXs[i] + p_width/2, rayToRender.back()->previousYs[i] + p_height/2, 5);
		}

	}
	// Update Screen
  	SDL_RenderPresent(sdl_renderer);


}


void Display::DrawCircle(int centreX, int centreY, int radius)
{
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(sdl_renderer, centreX + dx, centreY + dy);
            }
        }
    }
}

