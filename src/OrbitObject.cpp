#include <algorithm>
#include <iostream>
#include <chrono>
#include "OrbitObject.h"

// init static variable
int OrbitObject::_idCnt = 0;

std::mutex OrbitObject::_mtx;

void OrbitObject::setPosition(double r, double theta)
{
    _posR = r;
    _posTheta = theta;
}

void OrbitObject::getPosition(double &r, double &theta)
{
    r = _posR;
    theta = _posTheta;
}

void OrbitObject::setVelocity(double vR, double vTheta)
{
    _velR = vR;
    _velTheta = vTheta;
}

void OrbitObject::getVelocity(double &vR, double &vTheta)
{
    vR = _velR;
    vTheta = _velTheta;
}

OrbitObject::OrbitObject(double size = 0) : _size(size)
{
    _type = ObjectType::asteroid;
    _id = _idCnt++;
}

OrbitObject::~OrbitObject()
{
    // set up thread barrier before this object is destroyed
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
}

OrbitObject::getSize()
{
    return _Size;
}

OrbitObject::Simulate()
{
    threads.emplace_back(std::thread(&OrbitObject::Orbit, this));

}

OrbitObject::Orbit(double &r, double &theta, double &x, double &y)
{
    //Initialise variables
    bool hasCollided = collisionCheck();

    //TODO: Implement velocity and position update using GR EOMs 
    // Assume updating every frame which can be 1000/60 ms.
    // In Game::Update() need to make sure close all the threads made in OrbitObject::Simulate()

    //In Game make a vector of smart pointers to all the orbit Objects so that render can iterate thru
}