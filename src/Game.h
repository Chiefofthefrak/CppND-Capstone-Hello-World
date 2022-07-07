#ifndef GAME_H
#define GAME_H

#include <vector>
#include <thread>
#include <mutex>

class Game
{
public:
    // constructor / desctructor
    Game();
    ~Game();

    // getter and setter
    std::vector<std::shared_ptr<OrbitObject>> getOrbiters();
    bool LightFired();

    // typical behaviour methods
    void Update();
    void readInput();

    // behaviour for specific actions
    void Win();
    void Lose();

   

protected:
        bool LightFired = false;
        std::vector<std::shared_ptr<OrbitObject>> orbitPointers; //Holds a vector of all orbitObjects made by the game
    };

#endif