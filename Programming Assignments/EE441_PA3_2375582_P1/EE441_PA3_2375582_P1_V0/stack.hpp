#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
#include <iostream>
/* Stack from lecture notes*/
using namespace std;

const int MaxStackSize=50;
template <class T>
class Stack
{
private:
    T stacklist[MaxStackSize];
    int top;
public:
    Stack(void); // constructor to initialize top
    //modification operations
    void Push(const T& item);
    T Pop(void);
    void ClearStack(void);
    //just copy top item without modifying stack contents
    T Peek(void) const;
    //check stack state returns top element value without removal
    int StackEmpty(void) const;
    //returns true if the stack is empty
    int StackFull(void) const;
    //returns true if the stack is full
};

/* Class implementation */
// constructor */

template <class T>
Stack<T>::Stack(void):top(-1)
{}

template <class T>
//Push
void Stack<T>::Push(const T& item)//
{
    //can not push if stack has exceeded its limits
    if (top==MaxStackSize-1)
    {
        cerr<<"Stack overflow"<<endl;
        exit(1);
    }
    // increment top and copy item into list
    top++;
    stacklist[top] = item;
}

template <class T>
//pop
T Stack<T>::Pop(void)
{
    T temp;
    // is stack empty nothing to pop
    if (top==-1)
    {
        cerr<<"Stack empty"<<endl;
        exit(1);
    }
    //record the top element
    temp=stacklist[top] ;
    //decrement top and return the earlier top element
    top--;
    return temp;
}

template <class T>
//clear stack
void Stack<T>::ClearStack(void)
{
    top = -1;
}

template <class T>
//Peek is the same as Pop, except top is not moved
T Stack<T>::Peek(void) const
{
    //just copy top item without modifying stack contents
    T temp;
    // is stack empty nothing to peek
    if (top==-1)
    {
        cerr<<"Stack empty"<<endl;
        exit(1);
    }
    //record the top element
    temp=stacklist[top] ;

    return temp;
}

template <class T>
//StackEmpty: returns true if the stack is empty
int Stack<T>::StackEmpty(void) const
{
    return top==-1;
}

template <class T>
//StackFull: returns true if the stack is full
int Stack<T>::StackFull(void) const
{
    return top==(MaxStackSize-1);
}


#endif // STACK_HPP_INCLUDED
