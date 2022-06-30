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
    void getOrbiters();

    // typical behaviour methods
    void Update();
    void readInput();

    // behaviour for specific actions
    void Win();
    void Lose();

protected:
        std::vector<OrbitObject> orbiters; //Holds a vector of all orbitObjects made by the game
    };

#endif