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
    OrbitObject(double size);
    ~OrbitObject();

    // getter and setter
    int getID() { return _id; }
    void setPosition(double r, double theta);
    void getPosition(double &r, double &theta);
    
    void setVelocity(double vR, double vTheta);
    void getVelocity(double &vR, double &vTheta);

    double getSize();


    ObjectType getType() { return _type; }

    // typical behaviour methods
    void Simulate();
    void Orbit(double &r, double &theta, double &x, double &y);
    void collisionCheck();


    double _posX, _posY;              // orbit position in cartesians

protected:
    ObjectType _type;                 // identifies the class type
    int _id;                          // every orbit object has its own unique id
    double _posR, _posTheta;          // orbit position in polars

    double _velR, _velTheta;          // orbit speed in polars
    std::vector<std::thread> threads; // holds all threads that have been launched within this object
    static std::mutex _mtx;           // mutex shared by all orbit objects for protecting cout 
    double _Size;

private:
    static int _idCnt; // global variable for counting object ids
    float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.

#endif