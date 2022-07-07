
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>


#include "Display.h"



int main(int argc, char* argv[]){

	if(SDL_Init(SDL_INIT_VIDEO)>0){
		std::cout << "SDL_INIT has Failed, ERROR: "<< SDL_GetError() << std::endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG))){
		std::cout << "IMG_INIT has failed, ERROR: "<< SDL_GetError() << std::endl;
	}

	// TESTING SDL REMOVE FOR FINAL
	RenderWindow window("GAME v1.0",1280,720);
	SDL_Quit();


	// TESTING SDL REMOVE FOR FINAL


	
return 0;
}

//TODO: Define Get time functionss