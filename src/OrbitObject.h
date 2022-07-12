#ifndef ORBITOBJECT_H
#define ORBITOBJECT_H

#include <vector>
#include <memory>

enum ObjectType
{
    asteroid,
    player,
    target
};

class OrbitObject
{
public:
    // constructor / desctructor
    OrbitObject(double size, ObjectType type, double _posX, double posY, double vX, double vY);

    //Copy and move Operators
    OrbitObject(OrbitObject &&) = default;


    // getter and setter
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
    bool collisionCheck();


protected:
    ObjectType _type;                 // identifies the class type
    int _id;                          // every orbit object has its own unique id
    double _posX, _posY;             // orbit position 
    double _vX, _vY;                  //Velocity
    double _Size;

private:
    static int _idCnt; // global variable for counting object ids
    float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.
};

#endif