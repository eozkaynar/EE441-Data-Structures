#include "operation_queue.hpp"
#include <iostream>
#include <cmath>

using namespace std;
// CLASS OPERATION
double Operation::apply_operation(double x)
{

    if      (operators == '+') // addition
        return x+number;

    else if (operators == '-') // subtraction
        return x-number;

    else if (operators == '*') // multiplication
        return x*number;

    else if (operators == '/') // division
    {
        if(number == 0)
        {
            cerr << "Division by zero" << endl;
            exit(1);
        }
        return x/number;
    }

    else if (operators == '^')
        return pow(x,number);  // power
    else
    {
        cerr <<"Invalid operator"<<endl;
        exit(1);
    }
}

// QUEUE

// Constructor

OperationQueue::OperationQueue(void): front(0),rear(0),count(0)
{}

// Queue Modification
// Delete first element of queue

Operation OperationQueue::Pop_Front(void)
{
    Operation temp;
    // If queue is empty nothing to pop
    if(count == 0)
    {
        cerr << "Queue is empty!" << endl;
        exit(1);
    }
    // reduce the number of element in the queue
    count--;
    // hold the front element of the data
    temp = qlist[front];
    // update the front indicator
    front = (front + 1)%MaxQueueSize;
    return temp;
};
// Push_Back : Add an element at the end of the array

void OperationQueue::Push_Back(Operation& item)
{
    // check if the queue is full or not
    if (count == MaxQueueSize)
    {
        // Discard oldest entry
        count--;
        front = (front + 1)%MaxQueueSize;
        qlist[rear] =item;
        // increase the rear indicator
        rear = (rear + 1)%MaxQueueSize;
    }
    // increase the number of elements in the queue
    count++;
    qlist[rear] =item;
    // increase the rear indicator
    rear = (rear + 1)%MaxQueueSize;

}
int OperationQueue::QLength(void) const
{
    return count;
}
int OperationQueue::QEmpty(void) const
{
    return count==0;
}
int OperationQueue::QFull(void) const
{
    return count==MaxQueueSize;
}
