#ifndef GAME_H
#define GAME_H

#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include "OrbitObject.h"

class Game
{
public:
    // constructor / desctructor
    Game(int screenwidth, int screenheight);
   // ~Game();

    // getter and setter
    std::vector<std::shared_ptr<LightRay>> getLightRay();
    std::vector<std::shared_ptr<OrbitObject>> getOrbiters();
    bool LightFired();

    // typical behaviour methods
    void Update();
    void readInput(int &mouseX, int &mouseY, bool &mousePressed);

    // behaviour for specific actions
    void Win();
    void Lose();

   

protected:

        bool lightFired = false;
        std::vector<std::shared_ptr<OrbitObject>> orbitPointers; //Holds a vector of all orbitObjects made by the game
        std::vector<std::shared_ptr<LightRay>> lightPointers; //Container for LightRay
       // std::vector<std::thread> threads; // holds all threads that have been launched within this game
    };

#endif