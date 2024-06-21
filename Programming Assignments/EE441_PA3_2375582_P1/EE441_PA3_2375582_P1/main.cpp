#include <iostream>
#include "adhoc.h"
#include <time.h>

using namespace std;

int main()
{
    // Seed for random number generation
    srand(time(0));

    Network network(0.6);
    vector<int> n1 = {2, 3, 4};
    vector<int> n2 = {1, 3, 4, 5};
    vector<int> n3 = {1, 2, 4};
    vector<int> n4 = {1, 2, 3, 6};
    vector<int> n5 = {2, 6, 7};
    vector<int> n6 = {4, 5, 7};
    vector<int> n7 = {5, 6};



    network.addNode(1, n1);
    network.addNode(2, n2);
    network.addNode(3, n3);
    network.addNode(4, n4);
    network.addNode(5, n5);
    network.addNode(6, n6);
    network.addNode(7, n7);

    Packet messagePacket(1, 6, "Hello world!");
    network.simulate(messagePacket);

    return 0;
}
