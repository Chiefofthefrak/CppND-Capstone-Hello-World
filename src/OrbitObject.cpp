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


void OrbitObject::Orbit() //Updates positions and velocities using Eulers method 
{
    double pi = 3.141592654;
    double forceConstant = 1000;

    //Initialise variables

    double x, y, vX, vY;
    getPosition(x,y);
    getVelocity(vX,vY);
    double r = std::sqrt(x*x + y*y);
    double force = -1*forceConstant/(r*r);

    //Update velocities and positions
    x += vX;
    y += vY;
    vX += force *  (x/r);
    vY += force *  (y/r);

    setPosition(x,y);
    setVelocity(vX,vY);

}
LightRay::LightRay(double size, ObjectType type, double posX, double posY, double vX, double vY) : _Size(size), _type(type), _posX(posX), _posY(posY), _vX(vX), _vY(vY)
{
    std::cout << 
}

void LightRay::Orbit() //Updates LightRay's position and adds to previous positions
{
    double pi = 3.141592654;
    double forceConstant = 1000;

    //Initialise variables

    double x, y, vX, vY;
    getPosition(x,y);
    getVelocity(vX,vY);

    //position and velocity update Newtonian Force
    double r = std::sqrt(x*x + y*y);
    double force = -1*forceConstant/(r*r);
    x += vX;
    y += vY;
    vX += force *  (x/r);
    vY += force *  (y/r);


    //Add positions to previous positions vector
    previousXs.push_back(x);
    previousYs.push_back(y);

    if (previousXs.size()>5){
        previousXs.pop_front();
        previousYs.pop_front();
    }

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

bool LightRay::collisionCheck(OrbitObject object)
{
    double objectX, objectY, objectSize;
    object.getPosition(objectX,objectY);

    double lightPosX, lightPosY;
    getPosition(lightPosX,lightPosY);

    double dx = std::abs(lightPosX - objectX);
    double dy = std::abs(lightPosY - objectY);

    if(dx <= objectSize and dy <= objectSize){
        std::cout << "Ray has collided with "<< object.getType() << std::endl;
        return true;
    }else{
        return false;
    }
}