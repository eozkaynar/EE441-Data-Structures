#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED
#include <iostream>

/* Queue from lecture notes*/
using namespace std;

const int MaxQSize=100;
template <class T>
class Queue
{
private:
    // Queue array and parameters
    int front, rear, count;
    T queuelist[MaxQSize];

public:
    // Constructor
    Queue(void);
    // Queue modification operations
    void QInsert(const T& item);
    T QDelete(void);
    void ClearQueue(void);

    // Queue access
    T QFront(void) const;

    // Queue test methods
    int QLength(void) const;
    int QEmpty(void) const;
    int QFull(void) const;
};
//constructor
template <class T>
Queue<T>::Queue(void): front(0), rear (0), count(0)
{}

// Insert item into the queue
template <class T>
void Queue<T>::QInsert(const T& item)
{
    // Terminate if queue is full
    if (count==MaxQSize)
    {
        cerr<<"Queue overflow!" <<endl;
        exit(1);
    }
    count++;
    queuelist[rear] =item;
    rear=(rear+1)%MaxQSize;
}

// Delete element from the front of the queue and return its value
template <class T>
T Queue<T>::QDelete(void)
{
    T temp;
    // if queuelist is empty
    if (count==0)
    {
        cerr<<"Deleting from an empty queue!"<<endl;
    }

    temp=queuelist[front];
    count--;
    front=(front+1) % MaxQSize;
    return temp;
}

template <class T>
void Queue<T>::ClearQueue(void)
{
    front=0;
    rear=0;
    count=0;
}

template <class T>
T Queue<T>::QFront(void) const
{
    T temp;
    // if queuelist is empty
    if (count==0)
    {
        cerr<<"Accessing to an empty queue!"<<endl;
    }

    temp  = queuelist[front];
    return temp;
}

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
