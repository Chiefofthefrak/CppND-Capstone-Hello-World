#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL_image.h>

#include <vector>
#include <thread>
#include <mutex>

 class RenderWindow
 {
 public:
 	// constructor / desctructor
 	RenderWindow(const char* p_title, int p_width, int p_height);

 	
 private:
	
	SDL_Window* window;
	SDL_Renderer* renderer;
 };

 
class Display
{
public:
    // constructor / desctructor
    Display();
    ~Display();

    // getter and setter


    // typical behaviour methods
    void Render();

    // behaviour for specific actions
    //
    
//TODO: Define key methods and Implement
protected:


    };



#endif