#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "OrbitObject.h"
#include "Display.h"
#include "Game.h"
#include "Input.h"


int main(int argc, char* argv[]){

	if(SDL_Init(SDL_INIT_VIDEO)>0){
		std::cout << "SDL_INIT has Failed, ERROR: "<< SDL_GetError() << std::endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG))){
		std::cout << "IMG_INIT has failed, ERROR: "<< SDL_GetError() << std::endl;
	}

	// TESTING SDL REMOVE FOR FINAL



	// TESTING SDL REMOVE FOR FINAL


	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.

	Game mainGame = new Game();
	Input mainInput = new Input();
	Display mainDisplay = new Display();


	while (true) {
	    frame_start = GetCurrentTimeMS(); // Current time in milliseconds

	    mainInput.receiveInput();
	    mainGame.Update();
	    mainDisplay.Render();
	    frame_end = GetCurrentTimeMS();

	    frame_duration = frame_end - frame_start;

	    if (frame_duration < target_frame_duration ) {
	        Sleep(target_frame_duration - frame_duration);
	    }
	}
return 0;
}

//TODO: Define Get time functionss