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
    Game();
    ~Game();

    // getter and setter
    std::vector<std::unique_ptr<OrbitObject>> getOrbiters();
    bool LightFired();

    // typical behaviour methods
    void Update();
    void readInput(double &mouseX, double &mouseY, bool &mousePressed);

    // behaviour for specific actions
    void Win();
    void Lose();

   

protected:

        bool lightFired = false;
        std::vector<std::unique_ptr<OrbitObject>> orbitPointers; //Holds a vector of all orbitObjects made by the game
        std::vector<std::thread> threads; // holds all threads that have been launched within this game
    };

#endif