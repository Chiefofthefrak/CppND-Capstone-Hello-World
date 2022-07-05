#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



 class RenderWindow
 {
 public:
 	// constructor / desctructor
 	RenderWindow(const char* p_title, int p_width, int p_height);
    ~RenderWindow();   
 	
 private:
	
	SDL_Window* window;
	SDL_Renderer* renderer;
 };

 
