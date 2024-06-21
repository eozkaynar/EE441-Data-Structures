#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED
#include <iostream>
using namespace std;

const int MaxStackSize = 20;
template <class T>
class Rod2D
{
    private:
        T rodlist[3][MaxStackSize];  // Rodlist for indicate 3 rod in the game
        int top[3];                  // Top array to point the nonzero top of the rod
    public:
        //Constructor
        Rod2D(void);
        // modification operations
        void Push(const T& item,int rodnum);
        // Pop nonzero top element of selected rod
        T Pop(int rodnum);
        //just copy top item of selected rod without modifying stack contents
        T Peek(int rodnum) const;
        // return the nonzero top of the selected rod
        int returnTop(int rodnum) const;
        // fill with zero to indicate empty stack positions
        void PushZero(int rodnum,int idx);
        // return a disc of the selected rod at desired position
        T ShowElement(int rodnum,int idx) const;

};

template<class T>
void Rod2D<T>::PushZero(int rodnum,int idx)
{
    // if the array is full
    if(top[rodnum] == MaxStackSize-1)
    {
        cerr << "Rod Overflow" << endl;
        exit(1);
    }
    rodlist[rodnum][idx] = 0;
}

template<class T>
Rod2D<T>::Rod2D(void)
{
    // initialize top with -1 to indicate empty stack
    for (int rodnum = 2; rodnum >= 0; rodnum--)
        top[rodnum] = -1;
    // Fill with zeros to indicate empty stack positions
    for (int j = MaxStackSize-1; j >= 0; j--)
    {
        rodlist[0][j] = 0;
        rodlist[1][j] = 0;
        rodlist[2][j] = 0;
    }

}

template<class T>
int Rod2D<T>::returnTop(int rodnum) const
{

    return top[rodnum];
}

template<class T>
void Rod2D<T>::Push(const T& item,int rodnum)
{
    // If the stack is full
    if(top[rodnum] == MaxStackSize-1)
    {
        cerr << "Rod Overflow" << endl;
        exit(1);
    }
    // Increase the top
    top[rodnum] = top[rodnum] + 1;
    // Push item
    rodlist[rodnum][top[rodnum]] = item;
}

template <class T>
T Rod2D<T>::Pop(int rodnum)
{
    T temp;
    // If the stack is empty
    if(top[rodnum] == -1)
    {
        cerr << "Rod is empty" << endl;
        exit(1);
    }
    // Push item
    temp = rodlist[rodnum][top[rodnum]];
    // Decrease the top
    top[rodnum] = top[rodnum] - 1;
    return temp;
}
template <class T>
T Rod2D<T>::Peek(int rodnum) const
{
    T temp;
    // If stack is empty
    if(top[rodnum] == -1)
    {
        return 0;
    }
    // Peek element
    temp = rodlist[rodnum][top[rodnum]];
    return temp;
}

template <class T>
T Rod2D<T>::ShowElement(int rodnum,int idx) const
{
    return rodlist[rodnum][idx];
}




#endif // ARRAY_HPP_INCLUDED
