#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

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

#endif // STACK_HPP_INCLUDED
