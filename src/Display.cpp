#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Display.h"

RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height) : window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOW);

	if(window == NULL){
		std::cout << "Window failed to initialise. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);


}