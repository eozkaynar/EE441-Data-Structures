#ifndef OPERATION_QUEUE_HPP_INCLUDED
#define OPERATION_QUEUE_HPP_INCLUDED
#include <iostream>
#include <stdio.h>

using namespace std;

class Operation
{
    private:
        double number;     // number that is held to apply operation
        char   operators;  // operators "+", "-", "*", "/", "^"

    public:
        // constructor
        Operation(double n, char o) :number(n),operators(o)
        {}
        Operation(void){}
        // method to apply operation
        double apply_operation(double x);
};
const int MaxQueueSize = 10;

class OperationQueue
{
    private:

        // queue array and its parameters
        int front = 0,rear = 0, count = 0;
        Operation qlist[MaxQueueSize];

    public:
        // constructor
        OperationQueue(void);
        // Queue modification
        Operation Pop_Front(void);
        void Push_Back (Operation& item);
        // Queue test methods
        int QLength(void) const;
        int QEmpty(void) const;
        int QFull(void) const;

};



#endif // OPERATION_QUEUE_HPP_INCLUDED
