#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED
#include <iostream>
/* Queue from lecture notes*/
using namespace std;

const int MaxQSize=50;
template <class T>
class Queue
{
private:
    // queue array and its parameters
    int front, rear, count;
    T qlist[MaxQSize];

public:
    //constructor
    Queue(void); // initialize data members

    //queue modification operations
    void QInsert(const T& item);
    T QDelete(void);
    void ClearQueue(void);

    // queue access
    T QFront(void) const;

    // queue test methods
    int QLength(void) const;
    int QEmpty(void) const;
    int QFull(void) const;
};

/* Class implementation */
// Queue constructor

//initialize queue front, rear, count
template <class T>
Queue<T>::Queue(void): front(0), rear (0), count(0)
{}

//Queue Modification Operations

// QInsert: insert item into the queue
template <class T>
void Queue<T>::QInsert(const T& item)
{
    // terminate if queue is full
    if (count==MaxQSize)
    {
        cerr<<"Queue overflow!" <<endl;
        exit(1);
    }
    //increment count, assign item to qlist and update rear
    count++;
    qlist[rear] =item;
    rear=(rear+1)%MaxQSize;
}

//QDelete : delete element from the front of the queue and return its value
template <class T>
T Queue<T>::QDelete(void)
{
    T temp;
    // if qlist is empty, terminate the program
    if (count==0)
    {
        cerr<<"Deleting from an empty queue!"<<endl;
    }
    //record value at the front of the queue
    temp=qlist[front];
    //decrement count, advance front and return former front
    count--;
    front=(front+1) % MaxQSize;
    return temp;
}

//clear queue
template <class T>
void Queue<T>::ClearQueue(void)
{
    front=0;
    rear=0;
    count=0;
}

//Queue Access
template <class T>
T Queue<T>::QFront(void) const
{
    T temp;
    // if qlist is empty, terminate the program
    if (count==0)
    {
        cerr<<"Accessing to an empty queue!"<<endl;
    }
    //record value at the front of the queue
    temp=qlist[front];
    return temp;
}

//Queue Test Methods

template <class T>
int Queue<T>::QLength(void) const
{
    return count;
}

template <class T>
int Queue<T>::QEmpty(void) const
{
    return count==0;
}

template <class T>
int Queue<T>::QFull(void) const
{
    return count==MaxQSize;
}

#endif // QUEUE_HPP_INCLUDED
