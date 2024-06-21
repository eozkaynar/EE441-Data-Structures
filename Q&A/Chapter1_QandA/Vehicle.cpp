#include "Vehicle.hpp"

int Vehicle::GetWheels() const
{
    return wheels;
}

void Vehicle::SetWheels(int w)
{
    wheels = w;
}

string Vehicle::GetColor() const
{
    return color;
}

void Vehicle::SetColor(string c)
{
    color = c;
}

int HumanTransport::GetPassengers() const
{
    return passengers;
}

void HumanTransport::SetPassengers(int p)
{
    passengers = p;
}

void HumanTransport::PrintInfo() const
{
    cout << "Wheels: " << GetWheels() << endl << "Passengers: " <<
            passengers << endl << "Color: " << GetColor() << endl;
}

int Logistics::GetPayload() const
{
    return payload;
}

void Logistics::SetPayload(int p)
{
    payload = p;
}

bool Logistics::GetTrailer() const
{
    return trailer;
}

void Logistics::SetTrailer(bool t)
{
    trailer = t;
}

void Logistics::PrintInfo() const
{
    cout << "Wheels: " << GetWheels() << endl << "Trailers: ";
    if(trailer == true)
        cout << "has trailers" << endl;
    else
        cout << "no trailers" << endl;
    cout << "Payload: " << payload << endl << "Color: " << GetColor() <<
         endl;
}

string Bus::GetOwner() const
{
    return owner;
}

void Bus::SetOwner(string o)
{
    owner = o;
}

void Bus::PrintInfo() const
{
    cout << "Wheels: " << GetWheels() << endl << "Passengers: " <<
             GetPassengers() << endl << "Color: " << GetColor() << endl <<
            "Owner: " << owner << endl;
}
