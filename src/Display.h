#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <SDL.h>

#include "OrbitObject.h"




 class Display
 {
 public:
 	// constructor / desctructor
 	Display(const char* p_title, int p_width, int p_height);
    ~Display();  

    //Typical Behaviour methods
    Render(vector<OrbitObject> Orbiters);
    DrawCircle(int centreX, int centreY, int radius); //Draw Circle using Midpoint Circle algorithm taken from https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
 	
 private:
	
	SDL_Window* sdl_window;
	SDL_Renderer* sdl_renderer;

	const int p_width;
    const int p_height;
 };

 
