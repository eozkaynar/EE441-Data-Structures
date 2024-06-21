#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
#include <iostream>
/* Stack from lecture notes*/
using namespace std;

const int MaxStackSize=100;
template <class T>
class Stack
{
private:
    T stacklist[MaxStackSize];
    int top;
public:
    Stack(void):top(-1)
    {} // constructor to initialize top
    //modification operations
    void Push(const T& item)//
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
    T Pop(void)
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
    void ClearStack(void)
    {
        top = -1;
    }
    T Peek(void) const
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

    //check stack state returns top element value without removal
    int StackEmpty(void) const
    {
        return top==-1;
    }
    //returns true if the stack is empty
    int StackFull(void) const
    {
        return top==(MaxStackSize-1);
    }
    //returns true if the stack is full
};

#endif // STACK_HPP_INCLUDED
