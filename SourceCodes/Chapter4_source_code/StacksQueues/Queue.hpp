#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

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

#endif // QUEUE_HPP_INCLUDED
