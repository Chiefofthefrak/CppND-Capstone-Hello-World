#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <SDL2/SDL.h>

#include "OrbitObject.h"
#include "Game.h"




 class Display
 {
 public:
 	// constructor / desctructor
 	Display(int p_width, int p_height);
    ~Display();  

    //Typical Behaviour methods
    void Render(Game game);
    void DrawCircle(int centreX, int centreY, int radius); //Draw Circle using Midpoint Circle algorithm taken from https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
 	
 private:
	
	SDL_Window* sdl_window;
	SDL_Renderer* sdl_renderer;

	const int p_width;
    const int p_height;
 };

 
#endif