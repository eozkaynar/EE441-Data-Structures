#include "adhoc.h"
#include "queue.hpp"
#include "stack.hpp"

#include <iostream>
#include <algorithm>

#define INT_MAX 2147483647

using namespace std;

// The function to get index value of key in the vector
int getIndex(vector<int> v, int key)
{
    auto it = find(v.begin(), v.end(), key);

    // If element was found
    if (it != v.end())
    {
        // Calculating the index of the key
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not present in the vector
        return -1;
    }
}

using namespace std;

// ***** Packet Class *****

//a hash function for the packet class
size_t hash_function(int sourceId,int destId,string message)
{
    size_t hash_sourceId = static_cast<size_t>(sourceId);
    size_t hash_destId   = static_cast<size_t>(destId);
    size_t hash_message  = 0;
    for (char c : message)
    {
        hash_message = (hash_message*31) + static_cast<size_t>(c); // prime number 31 to reduce collisions
    }

    // XOR
    return hash_sourceId ^ ((hash_destId) << 1) ^ ((hash_message) << 1);

}
//Constructors for the packet class
// Default constructor
Packet::Packet()
{
    hash  = hash_function(sourceId,destId,message);
}

// Constructor
Packet::Packet(int sourceId, int destId, std::string message): sourceId(sourceId), destId(destId), message(message)
{
        hash = hash_function(sourceId,destId,message);
}

// Implement the functions getSourceId, getDestId, getMessage

int Packet::getSourceId()
{
    return sourceId;
}

int Packet::getDestId()
{
    return destId;
}

std::string Packet::getMessage()
{
    return message;
}

// the function checkIntegrity. Recalculate the hash value and compare
// it to the member parameter

bool Packet::checkIntegrity()
{
    return hash == hash_function(sourceId,destId,message);
}

// the function corrupt. change a random character in the message to a
// random ASCII character

void Packet::corrupt()
{
    int message_length; // message length the create a random index for change random character of message
    int random_index;   // the index value to change a random character
    char random_char;   // random ASCII character
    // ASCII printable char range
    int start_ascii = 32;
    int end_ascii   = 126;


    message_length = message.length();
    random_index   = rand() % message_length;

    random_char    = rand() % (end_ascii-start_ascii+1) + start_ascii;
    message[random_index] = char(random_char);
}

// ***** MacPacket Class *****

// Constructors
// Default constructor
MacPacket::MacPacket() : type(MacPacketType::Empty) {}
// Constructor
MacPacket::MacPacket(MacPacketType type, int macSourceId, int macDestId, vector<int>& path, Packet& packet):type(type),macSourceId(macSourceId),
macDestId(macDestId),path(path),packet(packet) {}

// Implement static functions

MacPacket MacPacket::createMessagePacket(int macSourceId, int macDestId, std::vector<int>& path, Packet& packet)
{
    return MacPacket(MacPacketType::Message,macSourceId,macDestId,path,packet);
}

MacPacket MacPacket::createSuccessPacket(int macSourceId, int macDestId, std::vector<int>& path)
{
    Packet packet;
    return MacPacket(MacPacketType::Success,macSourceId,macDestId,path,packet);
}

MacPacket MacPacket::createFailurePacket(int macSourceId, int macDestId, std::vector<int>& path)
{
    Packet packet(0,0,"");
    return MacPacket(MacPacketType::Failure,macSourceId,macDestId,path,packet);
}

// Implement functions
MacPacketType MacPacket::getType()
{
    return type;
}

int MacPacket::getMacSourceId()
{
    return macSourceId;
}

int MacPacket::getMacDestId()
{
    return macDestId;
}

vector<int>& MacPacket::getPath()
{
    return path;
}

Packet& MacPacket::getPacket()
{
    return packet;
}

// ***** Node Class *****

// Constructors
// Default constructor
Node::Node():id(0)
{}
// Constructor
Node::Node(int id, vector<int>& neighbors):id(id),neighbors(neighbors) {}

// the functions getId and getNeighbors.

int Node::getId()
{
    return id;
}

vector<int>& Node::getNeighbors()
{
    return neighbors;
}

// Receive function
MacPacket Node::receive(MacPacket packet)
{

    Packet p = packet.getPacket();
    string message = p.getMessage();
    vector<int> path = packet.getPath();
    int nextReceiver, nextReceiverIdx;
    MacPacketType packetType = packet.getType();

    if(packetType == MacPacketType::Message)
    {

        if(p.checkIntegrity())
        {

                    if(id == p.getDestId()) // if the node is final destination
                    {
                        reverse(path.begin(),path.end());
                        cout << "[Node " << id << "]" << " Message successfully received: '" << message << "'. Sending acknowledgment to Node "<< packet.getMacSourceId() <<"..."<<endl;
                        MacPacket successPacket = MacPacket::createSuccessPacket(id,packet.getMacSourceId(),path);
                        return successPacket;

                    }
                    else
                    {
                        buffer = packet;
                        nextReceiverIdx = getIndex(path,id) + 1;
                        nextReceiver = path[nextReceiverIdx];
                        cout << "[Node " << id << "] Packet received. "<<"Sending to Node "<< nextReceiver <<"..."<<endl;
                        MacPacket newPacket = MacPacket::createMessagePacket(id, nextReceiver, path, p);
                        return newPacket;

                    }
                }
        else
        {
                nextReceiverIdx = getIndex(path,id) - 1;
                nextReceiver = path[nextReceiverIdx];
                cout << "[Node " << id << "]" << " Packet corrupted: '" << message << "'. Requesting resend from Node "<< nextReceiver <<"..."<<endl;
                return MacPacket::createFailurePacket(id, nextReceiver, packet.getPath());
        }

    }
    else if(packetType == MacPacketType::Success)
    {
                buffer = packet;
                nextReceiverIdx = getIndex(path,id) + 1;
                nextReceiver = path[nextReceiverIdx];
                cout << "[Node " << id << "]" << " Acknowledgment received. Sending to Node " << nextReceiver <<"..."<<endl;
                return MacPacket::createSuccessPacket(id, nextReceiver, path);
//                if(id == 1) //p.getSourceId()
//                {
//
//                    cout << "[Node " << id << "]" << " Acknowledgment received." <<endl;
//                    return MacPacket();
//                }
//                else
//                {
//                    nextReceiverIdx = getIndex(path,id) + 1;
//                    nextReceiver = path[nextReceiverIdx];
//                    cout << "[Node " << id << "]" << " Acknowledgment received. Sending to Node " << nextReceiver <<"..."<<endl;
//                    return MacPacket::createSuccessPacket(id, nextReceiver, path);
//                }
    }
        else if(packetType == MacPacketType::Failure)
    {
                Packet pck = buffer.getPacket();
                cout << "[Node " << packet.getMacDestId() << "]" << " Resending previous packet to Node  " << packet.getMacSourceId() <<"..."<<endl;
                return MacPacket::createMessagePacket(packet.getMacDestId(),packet.getMacSourceId(),path,pck);
    }
    else if(packetType == MacPacketType::Empty)
    {
                    cout << "[Node " << id << "]" << " Acknowledgment received." <<endl;
                    return MacPacket();
    }

}

// ***** Network Class *****
// Constructor

Network::Network(float corruptionRate):corruptionRate(corruptionRate) {}

//functions

Node* Network::getNode(int id)
{
    for (Node& node : nodes)
    {
        if (node.getId() == id)
        {
            return &node;
        }
    }
    return nullptr;
}

void Network::addNode(int id, std::vector<int>& neighbors)
{
    bool flag = true;
    int NeighborId;
    Node* NeighborNode;
    // Create a new node
    Node NewNode(id,neighbors);
    // Add node to nodes vector
    nodes.push_back(NewNode);
    for (int i = 0; i<neighbors.size(); i++)
    {
        // Neighbor's Id
        NeighborId     = neighbors[i];
        // Get the neighbor
        NeighborNode   = getNode(NeighborId);

        if(NeighborNode != NULL)
        {

            vector<int>neighborsofneigbors = NeighborNode->getNeighbors();
            for (int n : neighborsofneigbors)
            {
                if(n == id)
                    flag = false;
            }
            if (flag)
                NeighborNode->getNeighbors().push_back(id);
        }

    }

}
//void Network::addNode(int id, std::vector<int>& neighbors)
//{
//    int NeighborId;
//    Node* NeighborNode;
//    // Create a new node
//    Node NewNode(id,neighbors);
//    // Add node to nodes vector
//    nodes.push_back(NewNode);
//    for (int neigbor : neighbors)
//    {
//        NewNode.getNeighbors().push_back(neigbor);
//    }
//}

void Network::removeNode(int id)

{

    for(int i = 0; i<nodes.size(); i++)
    {

        vector<int>& neighbors = nodes[i].getNeighbors();
        for (int neighbor : neighbors)
        {

            if(neighbor == id)
            {
                auto i = find(begin(neighbors), end(neighbors), id);
                neighbors.erase(i);
            }

        }
    }
}

std::vector<int> Network::calculatePath(int source, int destination)
{

//    int numOfNodes = nodes.size();
//    //queue
//    Queue<int> q;
//
//    Stack<int> PathStack;
//
//    bool visited[numOfNodes+1]; // starts from index 1
//    int dist[numOfNodes+1];     // distances starting from index 1
//
//    vector<int> path(numOfNodes+1); //previous nodes
//    vector<int> prev(numOfNodes+1); // previous nodes (path)
//
//     Set all distances, previous nodes and marks
//    for (int i = 1; i <= numOfNodes; i++) {
//        visited[i] = false;
//        dist[i]    = INT_MAX;
//        prev[i]    = -1;
//    }
//
//
//     Update source
//    visited[source] = true;
//    dist[source]    = 0;
//
//     Insert the source node
//    q.QInsert(source);
//
//     BFS algorithm
//    while (!q.QEmpty()) {
//
//         top element of q
//        int u = q.QFront();
//        q.QDelete();
//
//
//         Find neighbors corresponding node
//         nodes vector starts with 0
//        vector<int> neighbors = nodes[u-1].getNeighbors();
//
//        for (int i = 0; i < neighbors.size(); i++) {
//            if(dist[neighbors[i]] > dist[u] + 1)
//            {
//                dist[neighbors[i]] = dist[u] + 1;
//                prev[neighbors[i]] = u;
//                q.QInsert(neighbors[i]);
//            }
//        }
//    }
//    for(int p: prev)
//        cout << p << endl;
//    PathStack.Push(destination);
//    int vertex = destination; //
//    while (vertex != source)
//    {
//        vertex = prev[vertex];
//        PathStack.Push(vertex);
//    }
//    int i = 0;
//    while(!PathStack.StackEmpty())
//    {
//
//        path[i] = PathStack.Pop();
//        cout<< path[i] << endl;
//        i++;
//    }
//    return path;

    int numOfNodes = nodes.size();
    // queue
    Queue<int> q;

    Stack<int> PathStack;

    bool visited[numOfNodes+1]; // starts from index 1
    int dist[numOfNodes+1];     // distances starting from index 1

    vector<int> path(numOfNodes+1); //previous nodes
    vector<int> prev(numOfNodes+1); // previous nodes (path)

    // Set all distances, previous nodes and marks
    for (int i = 1; i <= numOfNodes; i++) {
        visited[i] = false;
        dist[i]    = INT_MAX;
        prev[i]    = -1;
    }


    // Update source
    visited[source] = true;
    dist[source]    = 0;

    // Insert the source node
    q.QInsert(source);

    // BFS algorithm
    while (!q.QEmpty()) {

        // top element of q
        int u = q.QFront();
        q.QDelete();

        // Find neighbors corresponding node
        // nodes vector starts with 0
        vector<int> neighbors = nodes[u-1].getNeighbors();
        for (int i = 0; i < neighbors.size(); i++) {

            if (visited[neighbors[i]]  == false) {
                // make the neighbor node visited
                visited[neighbors[i]] = true;
                // calculate distance

                dist[neighbors[i]] = dist[u] + 1;
                // update the previous node
                prev[neighbors[i]] = u;

                q.QInsert(neighbors[i]);
                // We stop BFS when we find
                // destination.
            }
        }
    }

    PathStack.Push(destination);
    int vertex = destination; //
    while (vertex != source)
    {
        vertex = prev[vertex];
        PathStack.Push(vertex);
    }
    int i = 0;
    while(!PathStack.StackEmpty())
    {
        path[i] = PathStack.Pop();
        i++;
    }

    // Remove zeros from path
    for(int p : path)
    {
        if(p == 0)
        {
            std::vector<int>::iterator index = remove(begin(path), end(path), 0);
            path.erase(index);
        }
    }



//    std::vector<int> path;
//
//    Queue<int> q;
//    std::unordered_map<int, int> parent;
//
//    q.QInsert(source);
//    parent[source] = -1;
//
//    while (!q.QEmpty())
//    {
//        int current = q.QFront();
//        q.QDelete();
//
//        if (current == destination)
//        {
//            // Reconstruct the path from destination to source
//            int node = destination;
//            while (node != -1)
//            {
//                path.insert(path.begin(), node);
//                node = parent[node];
//            }
//            break;
//        }
//
//        for (int neighbor : getNode(current)->getNeighbors())
//        {
//            if (parent.find(neighbor) == parent.end())
//            {
//                q.QInsert(neighbor);
//                parent[neighbor] = current;
//            }
//        }
//    }

    return path;
}

void Network::simulate(Packet packet)
{
    int counter;
    vector<int> path = calculatePath(packet.getSourceId(),packet.getDestId());

    int nodeId = packet.getSourceId();
    int destId = packet.getDestId();
    int sourceId = packet.getSourceId();

    string message_init = packet.getMessage();



    int idx = getIndex(path,nodeId);
    idx = path[idx];
    MacPacket massagePacket = MacPacket::createMessagePacket(sourceId, idx, path, packet);

    cout<< "Message to send: "<< message_init <<". Path:";
    for (int p : path)
    {
        cout << " -> "<< p;
    }
    cout<<endl;

    while (true) {
        counter++;
        Node* currentNode = getNode(nodeId);


        MacPacket responsePacket = currentNode->receive(massagePacket);
        path = responsePacket.getPath();
        packet = responsePacket.getPacket();
        MacPacketType packetType = responsePacket.getType();
        if(packetType == MacPacketType::Empty)
        {
            break;
        }
        else if(packetType == MacPacketType::Message)
        {
            //Corruption
            /////////////////////////
           if ((float)std::rand() / RAND_MAX < corruptionRate)
            {

                nodeId = responsePacket.getMacDestId();
                packet.corrupt();
                massagePacket = MacPacket::createMessagePacket(responsePacket.getMacSourceId(), responsePacket.getMacDestId(), path, packet);
            }

            nodeId = responsePacket.getMacDestId();
            massagePacket = MacPacket::createMessagePacket(responsePacket.getMacSourceId(), responsePacket.getMacDestId(), path, packet);

        }
        else if(packetType == MacPacketType::Success)
        {
            nodeId = responsePacket.getMacDestId();
            massagePacket = MacPacket::createSuccessPacket(responsePacket.getMacSourceId(),nodeId ,path);
            if (nodeId == sourceId )
                massagePacket = MacPacket();
        }
        else if(packetType == MacPacketType::Failure)
        {
            nodeId = responsePacket.getMacDestId();
            massagePacket = MacPacket::createFailurePacket(responsePacket.getMacSourceId(),nodeId ,path);
        }
    }
}
