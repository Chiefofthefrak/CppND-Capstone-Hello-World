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
void Display::ClearScreen(){
	//Clear Screen
	SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00,0x26, 0xFF);
	SDL_RenderClear(sdl_renderer);

	// Render Central BH
	SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00,0x00, 0xFF);
	DrawDisk(p_width/2, p_height/2, p_width/8);
}

void Display::Render(Game game){

	ClearScreen();

	// Render Orbiters
	auto orbitersToRender = game.getOrbiters();
	double orbiterPosX, orbiterPosY;
	for(auto &Orbiter : orbitersToRender){ //Render depending on what objectType Orbiter is
		auto radius = Orbiter->getSize();

		Orbiter->getPosition(orbiterPosX,orbiterPosY);
		orbiterPosX += p_width/2;
		orbiterPosY += p_height/2;

		switch(Orbiter->getType()){
			case ObjectType::player:
				SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x4B,0xFF, 0xFF);
				DrawDisk(orbiterPosX, orbiterPosY, radius);
				break;
			
			case ObjectType::target:
				SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00,0x00, 0xFF);
				DrawDisk(orbiterPosX, orbiterPosY, radius);
				break;
			
			default:
				SDL_SetRenderDrawColor(sdl_renderer, 0xAF, 0xAF,0xAF, 0xFF);
				DrawDisk(orbiterPosX, orbiterPosY, radius);
				break;
			
		}

	}

	// Render Light Ray
	if(game.LightFired()){
		auto raysToRender = game.getLightRay();

		for (auto &ray : raysToRender){
			int rayR, rayG, rayB;
			ray->getColour(rayR ,rayG, rayB);
			SDL_SetRenderDrawColor(sdl_renderer, rayR,rayG,rayB,0xEE);
			for(int i = 0; i<= ray->previousXs.size(); i++ ){ //Render each light ray as 5 circles at last 5 positions of ray
				DrawDisk(ray->previousXs[i] + p_width/2, ray->previousYs[i] + p_height/2, 5);
			}
		}

	}

	// Update Screen
  	SDL_RenderPresent(sdl_renderer);

  	//Present End Screen if won 
 	if (!game.Running()){ //target object explodes followed by black screen and win message
			double targetX, targetY, targetRadius;
			orbitersToRender[3]->getPosition(targetX,targetY);
			targetRadius = orbitersToRender[3]->getSize();
			std::cout << "Got to rendering " << std::endl;

			ClearScreen();
			SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00,0x00, 0xFF);
			DrawCircle(targetX,targetY,targetRadius + 10);
			DrawCircle(targetX,targetY,targetRadius + 20);
			DrawCircle(targetX,targetY,targetRadius + 30);
			SDL_RenderPresent(sdl_renderer);
			SDL_Delay(300);
			std::cout << "You Win! " << std::endl;
	} 	


}


void Display::DrawDisk(int centreX, int centreY, int radius)
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

