#ifndef ORBITOBJECT_H
#define ORBITOBJECT_H

#include <vector>
#include <memory>
#include <deque>

enum ObjectType
{
    asteroid,
    player,
    target,
    light
};

class OrbitObject
{
public:
    // constructor / desctructor
    OrbitObject(double size, ObjectType type, double _posX, double posY, double vX, double vY);


    // getters and setters
    int getID() { return _id; }
    void setPosition(double x, double y);
    void getPosition(double &x, double &y);
    
    void setVelocity(double vX, double vY);
    void getVelocity(double &vX, double &vY);

    double getSize();


    ObjectType getType() { return _type; }
    void setType(ObjectType newType) {_type = newType;}

    // typical behaviour methods
    void Orbit();



protected:
    ObjectType _type;                 // identifies the class type
    int _id;                          // every orbit object has its own unique id
    double _posX, _posY;              // orbit position 
    double _vX, _vY;                  //Velocity
    double _Size;

private:
    static int _idCnt; // global variable for counting object ids
    float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.
};

class LightRay 
{
public:
    //Constructor
    LightRay(double size, ObjectType type, double _posX, double posY, double vX, double vY);
    //Previous Position of lightRay
    std::deque<double> previousXs;
    std::deque<double> previousYs; 


    //Getters and Setters
    void setPosition(double x, double y);
    void getPosition(double &x, double &y);
    
    void setVelocity(double vX, double vY);
    void getVelocity(double &vX, double &vY);

    void setColour(int r, int g, int b);
    void getColour(int &r, int &g, int &b);

    //Orbit with higher force constant and adding previous positions to vectors
    void Orbit();
    void absorb();

    bool collisionCheck( OrbitObject object); //Checks if lightRay is within radius distance of an object

protected:
    ObjectType _type;                 // identifies the class type
    double _posX, _posY;              // orbit position 
    double _vX, _vY;                  //Velocity
    double _Size;                     //Radius

    int colourR = 150; //RGB colour of the ray
    int colourG = 20;
    int colourB = 150;
};

#endif