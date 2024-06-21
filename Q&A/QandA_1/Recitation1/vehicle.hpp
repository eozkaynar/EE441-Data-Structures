#include <iostream>
#include <stdio.h>
using namespace std;

class Vehicle {
    private:
        int wheels;     // number of wheels
        string color;   // color of vehicle
    public:
        Vehicle(int w = 4, string c = "white"); // Constructor
        void Info() const;
        int GetWheels() const;
        void SetWheels(int a);
        string GetColor() const;
        void SetColor(int c);
};

class HumanTransport:public Vehicle {
    private:
        int passengers; // number of passengers
    public:
        HumanTransport(int w, string c, int p):Vehicle(w,c),passengers(p){
        } // Constructor
        int GetPassengers() const;
        void SetPassengers(int p);
        void Info() const;
};
typedef HumanTransport Car;

class Logistics:public Vehicle{
    private:
        bool trailers;
        int payload;
    public:
        Logistics(int w,string c,bool t,int p):Vehicle(w,c),trailers(t),payload(p){
        }
        bool GetTrailers() const;
        void SetTrailers(bool t);
        int GetPayload() const;
        void SetPayload(int p);
        void Info() const;
};

typedef Logistics Truck;

class Bus:public HumanTransport{
    private:
        string owner;
    public:
        Bus(int w, string c, int p,string o):HumanTransport(w,c,p),owner(o){
         }
        string GetOwner() const;
        void SetOwner(string o);
        void Info() const;
};

