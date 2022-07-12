#include <SDL.h>
#include <iostream>
#include <vector>


#include "Display.h"
#include "OrbitObject.h"
#include "Game.h"

Display::Display(const int p_width, const int p_height) : window(NULL), renderer(NULL), p_height(p_height), p_width(p_width)
{
	sdl_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

	if(sdl_window == NULL){
		std::cout << "Window failed to initialise. Error: " << SDL_GetError() << std::endl;
	}

	sdl_renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);

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

	for(auto &Orbiter : orbitersToRender){ //TODO: Change depending on what type of pointer is in orbitPointers
		auto radius = Orbiter->getSize();

		if (Orbiter->getType() != ObjectType::asteroid){
			SDL_SetRenderDrawColor(sdl_renderer, 0x4B, 0x4B,0x4B, 0xFF);
			DrawCircle(Orbiter->_posX, Orbiter->_posY, radius);
		}
		else{
			SDL_SetRenderDrawColor(sdl_renderer, 0xAF, 0xAF,0xAF, 0xFF);
			DrawCircle(Orbiter->_posX, Orbiter->_posY, radius);
		}
	}

	// Render Light Ray
	/*if(game.LightFired() == true){
		SDL_SetRenderDrawColor(sdl_renderer, 0xAF, 0x00,0x4E, 0xFF);
		for(auto point : game.LightRay.previousPositions){ //TODO: Change depending on implementation of LightRay in Game
			DrawCircle(point._posX, point._posY, p_width/100);
		}

	}*/
	// Update Screen
  	SDL_RenderPresent(sdl_renderer);


}


void Display::DrawCircle(int centreX, int centreY, int radius)
{
   const int diameter = (radius * 2);

   int x = (radius - 1);
   int y = 0;
   int tx = 1;
   int ty = 1;
   int error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(sdl_renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(sdl_renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(sdl_renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(sdl_renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(sdl_renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(sdl_renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(sdl_renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(sdl_renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}
