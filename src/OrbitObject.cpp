#include <algorithm>
#include <iostream>
#include <math>
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


void OrbitObject::getVelocity(double &E, double &h)
{
    E = _E;
    h = _h;
}

OrbitObject::OrbitObject(double size, ObjectType type, double posR, double posTheta, double E, double h) : _size(size), _type(type)
_posR(posR), _posTheta(posTheta), _E(E), _h(h)
{

    _id = _idCnt++;
}

OrbitObject::~OrbitObject()
{
    // set up thread barrier before this object is destroyed
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
}


double OrbitObject::getSize() //returns the radius of the object
{
    return _Size;
}


void OrbitObject::Orbit() //Updates positions and velocities using Eulers method with a timestep equal to 1000/60 mS
{
    //Initialise variables
    float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.
    bool hasCollided = collisionCheck();

    double r, theta, vR, vTheta;
    getPosition(r,theta);
    getVelocity(E,h);

    //position update using GR EOMs 
    //assume updating every frame which can be 1000/60 ms.
    r += target_frame_duration*(std::sqrt(E-(1-(100/r))*(1+(h*h)/(r*r))));
    theta += h/(r*r);

    setPosition(r,theta);

}
bool OrbitObject::collisionCheck(){
    return false;
}