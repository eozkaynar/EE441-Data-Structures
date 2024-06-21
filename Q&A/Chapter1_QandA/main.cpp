#include "Vehicle.hpp"


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

    // Print info about vehicles
    cout << "======== Car 1 ==========:" << endl;
    cout << "Wheels: " << c1_wheels << endl << "Passengers: " <<
             c1_passengers << endl << "Color: " << c1_color << endl;

    cout << "======== Car 2 ==========:" << endl;
    cout << "Wheels: " << c2_wheels << endl << "Passengers: " <<
            c2_passengers << endl << "Color: " << c2_color << endl;

    cout << "======== Truck 1 ==========:" << endl;
    cout << "Wheels: " << t1_wheels << endl << "Trailers: ";
    if(t1_trailers == true)
        cout << "has trailers" << endl;
    else
        cout << "no trailers" << endl;
    cout << "Payload: " << t1_payload << endl << "Color: " << t1_color <<
         endl;

    cout << "======== Truck 2 ==========:" << endl;
    cout << "Wheels: " << t2_wheels << endl << "Trailers: ";
    if(t2_trailers == true)
        cout << "has trailers" << endl;
    else
        cout << "no trailers" << endl;
    cout << "Payload: " << t2_payload << endl << "Color: " << t2_color <<
        endl;

    cout << "======== Bus 1 ==========:" << endl;
    cout << "Wheels: " << b1_wheels << endl << "Passengers: " <<
             b1_passengers << endl << "Color: " << b1_color << endl <<
            "Owner: " << b1_owner << endl;

    // Object-Oriented Implementation
    cout << "\n OBJECT-ORIENTED IMPLEMENTATION \n\n";
    // Car-1
    Car c1(c1_wheels, c1_color, c1_passengers);
    // Car 2
    Car c2(c2_wheels, c2_color, c2_passengers);
    // Truck 1
    Truck t1(t1_wheels, t1_color, t1_payload, t1_trailers);
    // Truck 2
    Truck t2(t2_wheels, t2_color, t2_payload, t2_trailers);
    // Bus 1
    Bus b1(b1_wheels, b1_color, b1_passengers, b1_owner);

    // Print info about vehicles
    cout << "======== Car 1 ==========:" << endl;
    c1.PrintInfo();
    cout << "======== Car 2 ==========:" << endl;
    c2.PrintInfo();
    cout << "======== Truck 1 ==========:" << endl;
    t1.PrintInfo();
    cout << "======== Truck 2 ==========:" << endl;
    t2.PrintInfo();
    cout << "======== Bus 1 ==========:" << endl;
    b1.PrintInfo();

    return 0;
}
