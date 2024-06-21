#include "adhoc.h"
#include "queue.hpp"
#include "stack.hpp"

#include <iostream>

#include <algorithm>

using namespace std;

// Helper function to remove node
void removeNodesById(vector<Node>& nodes, int idToRemove)
{
    // Check for each node
    for (int i = 0 ; i < nodes.size()-1; i++)
    {
        // If corresponding node is found
        if (nodes[i].getId() == idToRemove)
        {
            // Swap elements at start and end indices
            // Push the corresponding node to end of the vector
            Node temp    = nodes[i];
            nodes[i]     = nodes[i+1];
            nodes[i+1]   = temp;

        }
    }
    // Delete the node from back
    nodes.pop_back();
}

// Remove zeros function for the path finding algorithm
void removeZeros(vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); )
    {
        if (*it == 0)         // If iterator pointing's value is 0
            it = v.erase(it); // Delete zeros
        else
            it++;             // Increase the iterator pointing
    }
}

// Reverse vector function to reverse path in receive
void reverseVector(vector<int>& v)
{
    int start_ind   = 0;
    int end_ind     = v.size() - 1;

    // Stop the process when the indices pass each other
    while (start_ind < end_ind)
    {
        // Swap elements at start and end indices
        int temp    = v[start_ind];
        v[start_ind]= v[end_ind];
        v[end_ind]  = temp;

        // Move indices towards each other
        ++start_ind;
        --end_ind;
    }
}

// The function to get index value of key in the vector
int getIndex(vector<int> v, int key)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == key) // If key is found
            return i;
    }
    // If the element is not found
    return -1;
}

int getIndex(int v[], int key)
{
    for (int i = 0; i < sizeof(v); ++i)
    {
        if (v[i] == key) // If key is found
            return i;
    }
    // If the element is not found
    return -1;
}

int getNodeIndex(vector<Node> v, int key)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].getId() == key) // If key is found
            return i;
    }
    // If the element is not found
    return -1;
}

// ***** Packet Class *****

// A hash function for the packet class
size_t hash_function(int sourceId,int destId,string message)
{
    // Convert from int to size_t
    // Hash values of source and dest
    size_t hash_sourceId = static_cast<size_t>(sourceId);
    size_t hash_destId   = static_cast<size_t>(destId);
    size_t hash_message  = 0;
    // Convert string message to size_t
    for (char c : message)
    {
        hash_message = hash_message + static_cast<size_t>(c);
    }
    // Mod
    return (hash_sourceId + hash_destId + hash_message) % 8191;

}

//Constructors for the packet class
// Default constructor
Packet::Packet()
{
    hash  = hash_function(0,0,"");
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

// The function checkIntegrity. Recalculate the hash value and compare
// it to the member parameter

bool Packet::checkIntegrity()
{
    return hash == hash_function(sourceId,destId,message);
}

// The function corrupt. change a random character in the message to a
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
    // Calculate random index in the length of message
    random_index   = rand() % message_length;

    // Calculate random char in the range of ASCII printable chars
    random_char    = rand() % (end_ascii-start_ascii+1) + start_ascii;
    // Corrupt the message

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
    Packet packet;
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

    int nextReceiver, nextReceiverIdx;
    Packet p                    = packet.getPacket(); // Packet inside the MacPacket
    string message              = p.getMessage();     // Message of the packet
    vector<int> path            = packet.getPath();   // Path
    MacPacketType packetType    = packet.getType();   // Type of MacPacket

    // If the received MacPacket Type is Message
    if(packetType == MacPacketType::Message)
    {
        // If the packet is not corrupted
        if(p.checkIntegrity())
        {
            buffer = packet;        // Add packet to buffer
            if(id == p.getDestId()) // If the node is final destination
            {
                reverseVector(path);// Reverse the path
                cout << "[Node " << id << "]" << " Message successfully received: '" << message << "'. Sending acknowledgment to Node "<< packet.getMacSourceId() <<"..."<<endl;
                MacPacket successPacket = MacPacket::createSuccessPacket(id,packet.getMacSourceId(),path); // Send the packet previous node
                return successPacket;

            }
            else
            {
                nextReceiverIdx = getIndex(path,id) + 1; // Find the index of next node
                nextReceiver    = path[nextReceiverIdx]; // Get next node
                cout << "[Node " << id << "] Packet received. "<<"Sending to Node "<< nextReceiver <<"..."<<endl;
                MacPacket newPacket = MacPacket::createMessagePacket(id, nextReceiver, path, p); // Send Message packet
                return newPacket;

            }
        }
        else
        {
                nextReceiverIdx = getIndex(path,id) - 1; // Find the index of next node
                nextReceiver    = path[nextReceiverIdx]; // Get next node
                cout << "[Node " << id << "]" << " Packet corrupted: '" << message << "'. Requesting resend from Node "<< nextReceiver <<"..."<<endl;
                return MacPacket::createFailurePacket(id, nextReceiver, path); // Send Failure packet
        }

    }
    // If the received MacPacket Type is Success
    else if(packetType == MacPacketType::Success)
    {
        buffer          = packet;                   // Add packet to buffer
        nextReceiverIdx = getIndex(path,id) + 1;    // Find the index of next node
        nextReceiver    = path[nextReceiverIdx];    // Get next node
        cout << "[Node " << id << "]" << " Acknowledgment received. Sending to Node " << nextReceiver <<"..."<<endl;
        return MacPacket::createSuccessPacket(id, nextReceiver, path); // Send Success packet
    }
    // If the received MacPacket Type is Failure
    else if(packetType == MacPacketType::Failure)
    {
        Packet packet_prev = buffer.getPacket(); // Get previous message from buffer
        cout << "[Node " << packet.getMacDestId() << "]" << " Resending previous packet to Node  " << packet.getMacSourceId() <<"..."<<endl;
        return MacPacket::createMessagePacket(packet.getMacDestId(),packet.getMacSourceId(),path,packet_prev); // Send Message packet to source node
    }
    // If the received MacPacket Type is Empty
    else if(packetType == MacPacketType::Empty)
    {
        cout << "[Node " << id << "]" << " Acknowledgment received." <<endl;
        return MacPacket(); // return Empty packet
    }

}

// ***** Network Class *****

// Constructor
Network::Network(float corruptionRate):corruptionRate(corruptionRate) {}

//functions

Node* Network::getNode(int id)
{
    // For each node in nodes
    for (Node& node : nodes)
    {
        if (node.getId() == id) // If the node id is equal to id
        {
            return &node;
        }
    }
    return nullptr; // If the id is not exists
}

void Network::addNode(int id, std::vector<int>& neighbors)
{
    bool FLAG_EXIST = true;
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
        // If the NeighborNode exists add Node to its neighbors
        if(NeighborNode != NULL)
        {
            vector<int> NeighbOfNeigb = NeighborNode->getNeighbors(); // Neighbors vector of neighbor of node
            for (int n : NeighbOfNeigb)
            {
                if(n == id) // If the node already exists in neighbors of its neighbors, make the flag false
                    FLAG_EXIST = false;
            }
            if (FLAG_EXIST) // If the node does not exists in neighbors of its neighbors, add to its neighbors' neighbors
                NeighborNode->getNeighbors().push_back(id);
        }
    }
}

void Network::removeNode(int id)

{
    // Check for each node
    for(Node& node : nodes)
    {
        // Remove node from neighbors vector
        vector<int>& neighbors = node.getNeighbors();
        // Check each neighbor of Node's neighbors
        for (int neighbor : neighbors)
        {
            // If removed node is found
            if(neighbor == id)
            {
                for (size_t j = 0; j < neighbors.size(); ++j)
                {
                    if (neighbors[j] == id)
                    {
                        neighbors.erase(neighbors.begin() + j);
                        break;
                    }
                }
            }

        }
    }
    // Remove Node
    removeNodesById(nodes, id);
}

std::vector<int> Network::calculatePath(int source, int destination)
{
    int numOfNodes = nodes.size();
    // Queue to Dijkstra's algorithm
    Queue<int> q;
    // Stack to get the path
    Stack<int> PathStack;

    int dist[numOfNodes+1];         // Distances

    vector<int> path(numOfNodes+1); // Path vector
    vector<int> prev(numOfNodes+1); // Previous nodes

    // Set all distances, previous nodes and marks
    for (int i = 1; i <= numOfNodes; i++) {
        dist[i]     = INT_MAX;
        prev[i]     = -1;
    }

    // Update source
    int source_ind = getNodeIndex(nodes,source);
    dist[source_ind]    = 0;

    // Insert the source node
    q.QInsert(source);

    // Unweighted Dijkstra's algorithm
    while (!q.QEmpty()) {

        // Top element of q
        int u = q.QFront();
        q.QDelete();

        // Find neighbors corresponding node
        int u_node = getNodeIndex(nodes,u);
        vector<int> neighbors = nodes[u_node].getNeighbors();

        for (int i = 0; i < neighbors.size(); ++i)
        {
            int ind = getNodeIndex(nodes,neighbors[i]);

            // If old distance is larger than new distance
            if(dist[ind] > dist[u_node] + 1)
            {
                dist[ind] = dist[u_node] + 1;    // Update the distance
                prev[ind] = u;                   // Update the previous node
                q.QInsert(neighbors[i]);         // Insert node to queue
            }
        }
    }

    int vertex = getNodeIndex(nodes,destination);
    // Insert the destination node to stack
    if ((prev[vertex]> 0) && (vertex != -1))
        PathStack.Push(destination);
    else
    {
        // If node does not exist.
        cerr<<"There is no path!" <<endl;
        exit(1);
    }
    int max_node = INT_MIN;
    // Max node index
    // Find max node index to determine valid vertex range 1-max_ind
    for (auto node : nodes)
    {
        if (node.getId() > max_node)
            max_node = node.getId();
    }

     // Start with destination node and find it previous node of vertex
    while (true)  // Until source node is reach, find previous nodes from prev vecttor
    {
        vertex = prev[vertex];
        if ((vertex < 0) || (vertex > max_node)) // It vertex does not in the valid range
            break;
        PathStack.Push(vertex);// Push the nodes to Path stack
        vertex = getNodeIndex(nodes,vertex);
    }

    int i = 0;
    // Until the PathStack empty
    while(!PathStack.StackEmpty())
    {
        path[i] = PathStack.Pop(); // Reverse PathStack to path
        i++;
    }

    // Remove zeros from path
    removeZeros(path);
    return path;
}

void Network::simulate(Packet packet)
{
    // Calculate path
    vector<int> path    = calculatePath(packet.getSourceId(),packet.getDestId());

    int nodeId          = packet.getSourceId();  // Initialize nodeId with SourceId
    int destId          = packet.getDestId();    // Destination id
    int sourceId        = packet.getSourceId();// Source id

    // Message to send
    string message_init = packet.getMessage();

    // Index of node in the path
    int idx             = getIndex(path,nodeId);
    int next            = path[idx];

    // Create MacPacket packet
    MacPacket messagePacket = MacPacket::createMessagePacket(sourceId, next, path, packet);

    // Print
    cout<< "Message to send: "<< message_init <<". Path:";
    for (int p : path)
    {
        cout << " -> "<< p;
    }
    cout<<endl;

    // ***** Simulation *****
    while (true) {

        // Get current node
        Node* currentNode           = getNode(nodeId);
        // Get sent packet from CurrentNode
        MacPacket responsePacket    = currentNode->receive(messagePacket);

        path                        = responsePacket.getPath();    // Update the path of responsePacket
        packet                      = responsePacket.getPacket();  // Update the packet of responsePacket
        MacPacketType packetType    = responsePacket.getType();    // Get the packet type of responsePacket
        // If the responsePacket is Empty
        if(packetType == MacPacketType::Empty)
        {
            break;
        }
        // If the responsePacket is Message
        else if(packetType == MacPacketType::Message)
        {
            //Corruption
           if ((float)rand() / RAND_MAX < corruptionRate)
            {
                nodeId = responsePacket.getMacDestId(); // Update nodeId
                packet.corrupt();                       // Corrupt the packet of responsePacket
                // Update the messagePacket
                messagePacket = MacPacket::createMessagePacket(responsePacket.getMacSourceId(), responsePacket.getMacDestId(), path, packet);
            }

            nodeId = responsePacket.getMacDestId(); // Update nodeId
            // Update the messagePacket
            messagePacket = MacPacket::createMessagePacket(responsePacket.getMacSourceId(), responsePacket.getMacDestId(), path, packet);

        }
        // If the responsePacket is Success
        else if(packetType == MacPacketType::Success)
        {
            nodeId = responsePacket.getMacDestId();// Update nodeId
            // Update the messagePacket
            messagePacket = MacPacket::createSuccessPacket(responsePacket.getMacSourceId(),nodeId ,path);
            // If the source packet is reached, return empty packet to stop simulation
            if (nodeId == sourceId )
                messagePacket = MacPacket();
        }
        // If the responsePacket is Failure
        else if(packetType == MacPacketType::Failure)
        {
            nodeId = responsePacket.getMacDestId();// Update nodeId
            // Update the messagePacket
            messagePacket = MacPacket::createFailurePacket(responsePacket.getMacSourceId(),nodeId ,path);
        }
    }
}
