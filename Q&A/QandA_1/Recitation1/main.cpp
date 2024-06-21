#include <iostream>
#include <stdio.h>
#include "vehicle.hpp"

using namespace std;
int main()
{
 // Car 1
 int c1_wheels = 4;
 int c1_passengers = 5;
 string c1_color = "green";
 // Car 2
 int c2_wheels = 4;
 int c2_passengers = 5;
 string c2_color = "blue";
 // Truck 1
 int t1_wheels = 6;
 bool t1_trailers = true;
 int t1_payload = 15000;
 string t1_color = "red";
 // Truck 2
 int t2_wheels = 4;
 bool t2_trailers = false;
 int t2_payload = 40000;
 string t2_color = "yellow";
 // Bus 1
 int b1_wheels = 4;
 int b1_passengers = 40;
 string b1_color = "black";
 string b1_owner = "my_tours";

 Car    c1(c1_wheels,c1_color,c1_passengers);
 Car    c2(c2_wheels,c2_color,c2_passengers);
 Truck  t1(t1_wheels,t1_color,t1_trailers,t1_payload);
 Truck  t2(t2_wheels,t2_color,t2_trailers,t2_payload);
 Bus    b1(b1_wheels,b1_color,b1_passengers,b1_owner);

 // Print info about vehicles
 std::cout << "======== Car 1 ==========:" <<  std::endl;
  std::cout << "Wheels: " << c1.GetWheels()<<  std::endl << "Passengers: " <<c1.GetPassengers() <<  std::endl << "Color: " << c1.GetColor() <<  std::endl;

  std::cout << "======== Car 2 ==========:" <<  std::endl;
std::cout << "Wheels: " << c2.GetWheels() <<  std::endl << "Passengers: " <<c2.GetPassengers() <<  std::endl << "Color: " << c2.GetColor() <<  std::endl;

  std::cout << "======== Truck 1 ==========:" <<  std::endl;
  std::cout << "Wheels: " << t1.GetWheels() <<  std::endl << "Trailers: ";
 if(t1.GetTrailers() == true)
  std::cout << "has trailers" <<  std::endl;
 else
  std::cout << "no trailers" << std:: endl;
  std::cout << "Payload: " << t1.GetPayload() <<  std::endl << "Color: " << t1.GetColor() <<std::endl;
  std::cout << "======== Truck 2 ==========:" <<  std::endl;
  std::cout << "Wheels: " << t2.GetWheels() <<  std::endl << "Trailers: ";
 if(t2.GetTrailers() == true)
  std::cout << "has trailers" <<  std::endl;
 else
  std::cout << "no trailers" <<  std::endl;
  std::cout << "Payload: " << t2.GetPayload() <<  std::endl << "Color: " << t2.GetColor() <<std::endl;
  std::cout << "======== Bus 1 ==========:" <<  std::endl;
  std::cout << "Wheels: " << b1.GetWheels() <<  std::endl << "Passengers: " <<b1.GetPassengers() <<  std::endl << "Color: " << b1.GetColor() <<  std::endl <<"Owner: " << b1.GetOwner() <<  std::endl;
 return 0;
}
