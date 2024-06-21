#include <iostream>
#include <stdlib>

const int MaxQSize = 50;

template <class T>
class Queue
{
     private:
        // queue array and its parameters
        int front,rear,count;
        T qlist[MaxQSize];

     public:
        Queue(void); //initialize data members
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
// initialize Queue front,rear,count

template <class T>
Queue<T>::Queue(void):front(f),rear(r),count(c)
{}

template <class T>
void Queue<T>::QInsert(const T& item)
{
    // terminate if queue is full
    if (count == MaxQSize)
    {
        cerr << "Queue overflow!" << endl;
        exit(1);
    }
    count++;
    qlist[rear] = item;
    rear = (rear+1) % MaxQSize;
}
//QDelete: delete element from the queue and return its value
template <class T>
T Queue<T>::QDelete(void)
{
    T temp;
    if(count == 0)
    {
        cerr << "Deleting from an empty queue!" << endl;
        exit(1);
    }
    temp = qlist[rear];
    count--;
    front = (front+1)%MaxQSize;
    return temp;
 }
 // clear Queue
 template <class T>
 void Queue<T>::ClearQueue(void)
 {
     front = 0, rear = 0, count = 0;
 }

template <class T>
T Queue<T>::QFront(void) const;
{
    T temp;
    if(count == 0)
    {
        cerr << "Accessing to an empty queue!" << endl;
        exit(1);
    }
    temp = qlist[front];
    return temp;
}
template <class T>
int Queue<T>::QLength(void) const{
    return count;
}
template <class T>
int Queue<T>::QEmpty(void) const{
    return count == 0;
}
template <class T>
int Queue<T>::QFull(void) const{
    return count == MaxQSize;
}



