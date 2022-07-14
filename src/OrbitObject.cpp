#include <algorithm>
#include <iostream>
#include <cmath>
#include "OrbitObject.h"

// init static variable
int OrbitObject::_idCnt = 0;


void OrbitObject::setPosition(double x, double y)
{
    _posX = x;
    _posY = y;
}

void OrbitObject::getPosition(double &x, double &y)
{
    x = _posX;
    y = _posY;
}


void OrbitObject::getVelocity(double &vX, double &vY)
{
    vX = _vX;
    vY = _vY;
}
void OrbitObject::setVelocity(double vX, double vY)
{
    _vX = vX;
    _vY = vY;
}
OrbitObject::OrbitObject(double size, ObjectType type, double posX, double posY, double vX, double vY) : _Size(size), _type(type), _posX(posX), _posY(posY), _vX(vX), _vY(vY)
{

    _id = _idCnt++;
}


double OrbitObject::getSize() //returns the radius of the object
{
    return _Size;
}


void OrbitObject::Orbit() //Updates positions and velocities using Eulers method with a timestep equal to 1000/60 mS
{
    double pi = 3.141592654;
    double forceConstant = 100;

    //Initialise variables
    float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.

    double x, y, vX, vY;
    getPosition(x,y);
    getVelocity(vX,vY);

    double theta;
    if (y==0){
        if (x>=0){theta = pi/2;}
        if (x<0){theta = 3*pi/2;}
    }else{
        theta = std::atan2(x,y);
    }
    double force = forceConstant/(x*x + y*y);
    x += vX;
    y += vY;
    vX += force* std::sin(theta);
    vY += force* std::cos(theta);

    //position update using GR EOMs 
    //assume updating every frame which can be 1000/60 ms
    setPosition(x,y);
    setVelocity(vX,vY);

}
LightRay::LightRay(double size, ObjectType type, double posX, double posY, double vX, double vY) : _Size(size), _type(type), _posX(posX), _posY(posY), _vX(vX), _vY(vY)
{

}

void LightRay::Orbit()
{
    double pi = 3.141592654;
    double forceConstant = 500;

    //Initialise variables
    float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.

    double x, y, vX, vY;
    getPosition(x,y);
    getVelocity(vX,vY);

    //Add positions to previous positions vector
    previousXs.push_back(x);
    previousYs.push_back(y);

    if (previousXs.size()>5){
        previousXs.pop_front();
        previousYs.pop_front();
    }


    double theta;
    if (y==0){
        if (x>=0){theta = pi/2;}
        if (x<0){theta = 3*pi/2;}
    }else{
        theta = std::atan2(x,y);
    }
    double force = forceConstant/(x*x + y*y);
    x += vX;
    y += vY;
    vX += force* std::sin(theta);
    vY += force* std::cos(theta);

    //position update using GR EOMs 
    //assume updating every frame which can be 1000/60 ms
    setPosition(x,y);
    setVelocity(vX,vY);

}

void LightRay::setPosition(double x, double y)
{
    _posX = x;
    _posY = y;
}

void LightRay::getPosition(double &x, double &y)
{
    x = _posX;
    y = _posY;
}


void LightRay::getVelocity(double &vX, double &vY)
{
    vX = _vX;
    vY = _vY;
}
void LightRay::setVelocity(double vX, double vY)
{
    _vX = vX;
    _vY = vY;
}