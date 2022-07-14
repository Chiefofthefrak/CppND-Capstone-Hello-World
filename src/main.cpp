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

	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	int target_frame_duration = 100; // milliseconds per frame at 60 frames per second.

	Game game(screenwidth,screenheight);
	Display display(screenwidth,screenheight);

	
	while (true) {
	    frame_start = SDL_GetTicks(); // Current time in milliseconds
	    game.Update();
	    display.Render(game);
	    frame_end = SDL_GetTicks();

	    frame_duration = frame_end - frame_start;

	    if (frame_duration < target_frame_duration) {
	      SDL_Delay(target_frame_duration - frame_duration);
	    }

	}

return 0;
}
