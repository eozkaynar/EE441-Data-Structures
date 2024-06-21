#include <iostream>
#include <stdio.h>

using namespace std;

class Vehicle
{
private:
    int wheels;
    string color;
public:
    Vehicle(int w, string c): wheels(w), color(c)
    {

    }
    int GetWheels() const;
    void SetWheels(int w);
    string GetColor() const;
    void SetColor(string c);
    void PrintInfo() const;
};

class HumanTransport:public Vehicle
{
private:
    int passengers;
public:
    HumanTransport(int w, string c, int p): Vehicle(w,c)
    {
        passengers = p;
    };
    int GetPassengers() const;
    void SetPassengers(int p);
    void PrintInfo() const;
};

class Logistics:public Vehicle
{
private:
    int payload;
    bool trailer;
public:
    Logistics(int w, string c, int p, bool t): Vehicle(w,c)
    {
        payload = p;
        trailer = t;
    }
    int GetPayload() const;
    void SetPayload(int p);
    bool GetTrailer() const;
    void SetTrailer(bool t);
    void PrintInfo() const;
};

typedef Logistics Truck;

class Bus:public HumanTransport
{
private:
    string owner;
public:
    Bus(int w, string c, int p, string o): HumanTransport(w, c, p)
    {
        owner = o;
    }
    string GetOwner() const;
    void SetOwner(string o);
    void PrintInfo() const;
};

typedef HumanTransport Car;
