#include <algorithm>
#include <iostream>
#include <cmath>
#include "OrbitObject.h"

// init static variable
int OrbitObject::_idCnt = 0;


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

OrbitObject::OrbitObject(double size, ObjectType type, double posR, double posTheta, double E, double h) : _Size(size), _type(type), _posR(posR), _posTheta(posTheta), _E(E), _h(h)
{

    _id = _idCnt++;
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

    double r, theta, E, h;
    getPosition(r,theta);
    getVelocity(E,h);
    

    //position update using GR EOMs 
    //assume updating every frame which can be 1000/60 ms.
    double a = (1-(100/r))*((r*r*r*r)/(h*h)+(r*r))/((r*r*r*r*E*E)/(h*h));
    r += r*r*E*(1-a/2 - (a*a)/8-(a*a*a)/16);
    theta += h/(r*r);


    setPosition(r,theta);

}
bool OrbitObject::collisionCheck(){
    return false;
}