#include <iostream>
#include <SDL2/SDL.h>

#include "OrbitObject.h"
#include "Display.h"
#include "Game.h"



int main(){
	int screenwidth = 720;
	int screenheight = 720;

	if(SDL_Init(SDL_INIT_VIDEO)>0){
		std::cout << "SDL_INIT has Failed, ERROR: "<< SDL_GetError() << std::endl;
	}
	auto initialTime = SDL_GetTicks();

	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	int target_frame_duration = 20; // milliseconds per frame

	Game game(screenwidth,screenheight);
	Display display(screenwidth,screenheight);

	
	while (game.Running()) {
	    frame_start = SDL_GetTicks(); // Current time in milliseconds
	    game.Update();
	    display.Render(game);
	    frame_end = SDL_GetTicks();

	    frame_duration = frame_end - frame_start;

	    if (frame_duration < target_frame_duration) {
	      SDL_Delay(target_frame_duration - frame_duration); //Make sure that each frame lasts at least 20 seconds
	    }
	    if (SDL_GetTicks() - initialTime >= 120000){
	    	std::cout << "Took Too long ";
	    	break;
	    }

	}

return 0;
}
