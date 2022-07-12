#ifndef ORBITOBJECT_H
#define ORBITOBJECT_H

#include <vector>
#include <thread>
#include <mutex>
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
    OrbitObject(double size, ObjectType type, double posR, double posTheta, double E, double h);
    ~OrbitObject();
    //Copy and move Operators


    // getter and setter
    int getID() { return _id; }
    void setPosition(double r, double theta);
    void getPosition(double &r, double &theta);
    
    void setVelocity(double vR, double vTheta);
    void getVelocity(double &vR, double &vTheta);

    double getSize();


    ObjectType getType() { return _type; }
    void setType(ObjectType newType) {_type = newType;}

    // typical behaviour methods
    void Simulate();
    void Orbit();
    void collisionCheck();


    double _posX, _posY;              // orbit position in cartesians

protected:
    ObjectType _type;                 // identifies the class type
    int _id;                          // every orbit object has its own unique id
    double _posR, _posTheta;          // orbit position in polars
    double _E, _h;                     //Energy + angular momentum
    std::vector<std::thread> threads; // holds all threads that have been launched within this object
    static std::mutex _mtx;           // mutex shared by all orbit objects for protecting cout 
    double _Size;

private:
    static int _idCnt; // global variable for counting object ids
    float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.
};

#endif