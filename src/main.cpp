#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <chrono>
#include <sys/time.h>
#include <ctime>

#include "OrbitObject.h"
#include "Display.h"
#include "Game.h"



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

	Game game = new Game();
	Display display = new Display();


	while (true) {
	    frame_start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); // Current time in milliseconds
	    game.Update();
	    display.Render(game);
	    frame_end = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	    frame_duration = frame_end - frame_start;

	    if (frame_duration < target_frame_duration ) {
	        Sleep(target_frame_duration - frame_duration);
	    }
	}
return 0;
}
