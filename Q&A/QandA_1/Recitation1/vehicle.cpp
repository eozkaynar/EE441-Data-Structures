
#include "vehicle.hpp"

Vehicle::Vehicle(int w, string c):wheels(w),color(c){
}


void Vehicle::Info() const{
    std::cout << "Wheels: "<< wheels << " Color: " << color << std::endl;
}

int Vehicle::GetWheels() const{
    return wheels;
}

void Vehicle::SetWheels(int w){
    wheels = w;
}

string Vehicle::GetColor()const{
    return color;
}

void Vehicle::SetColor(int c){
    color = c;
}
int HumanTransport::GetPassengers()const{
    return passengers;
}

void HumanTransport::SetPassengers(int p){
    passengers = p;
}
string Bus::GetOwner()const{
    return owner;
}

void Bus::SetOwner(string o){
    owner = o;
}

int Logistics::GetPayload()const{
    return payload;
}
void Logistics::SetPayload(int p){
    payload = p;
}

void HumanTransport::Info() const{
    Vehicle::Info();
    std::cout << "Passengers: "<< passengers <<std::endl;
}

void Bus::Info() const{
    HumanTransport::Info();
    std::cout << "Owner: "<<owner<<std::endl;
}

void Logistics::Info() const{
    Vehicle::Info();
    std::cout << "Trailers: "<<trailers<<" Payload: "<<payload<<std::endl;
}

bool Logistics::GetTrailers() const{
    return trailers;
}

void Logistics::SetTrailers(bool t) {
    trailers = t;
}
