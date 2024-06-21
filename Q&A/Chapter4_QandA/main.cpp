// Assuming that the stack and queue declarations and implementations are in "Stack.hpp" and "Queue.hpp", respectively.

#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
using namespace std;

void findinQ2(int key, Queue <int>& MyQ)
{
    int temp;
    for(int i=0; i<MyQ.QLength(); i++)
    {
        temp=MyQ.QDelete();
        if(temp!=key)
            MyQ.QInsert(temp); // total length would be the same
        else
            i--; // total length will decrease by one, and we need to traverse all elements once and only once
    }
}

void printBinary(int n)
{
    Stack<int> s;
    while (n > 0)
    {
        s.Push(n % 2);
        n = (n-s.Peek())/2;
    }
    while (!s.StackEmpty())
    {
        cout << s.Pop();
    }
    cout<<endl;
}

void reverseQueue(Queue<int> &myQ)
{
    int i;
    if(!myQ.QEmpty())
    {
        i = myQ.QDelete();
        reverseQueue(myQ);
        myQ.QInsert(i);
    }
}

template <class T>
void SwapStack(Stack<T> &myS)
{
	T topItem, bottomItem;
	Queue<T> myQ;
	// get topItem from the Stack
	topItem=myS.Pop();
	// move the rest of the myS into myQ
	while (!myS.StackEmpty())
	{
        myQ.QInsert(myS.Pop());
	};
	// load the bottomItem appropriately
	bottomItem=myQ.QDelete();
	// other operation(s)between myS and myQ if any necessary
    while (!myQ.QEmpty())
    {
        myS.Push(bottomItem);
        bottomItem=myQ.QDelete();
    }
    while (!myS.StackEmpty())
        myQ.QInsert(myS.Pop());
	// push either topItem or bottomItem into myS
	// whichever appropriate
	myS.Push(topItem);
	// push other items into myS by taking from myQ
	while (!myQ.QEmpty())
	{
        myS.Push(myQ.QDelete());
	};
	// push  either topItem or bottomItem into myS
	// whichever appropriate
	myS.Push(bottomItem);
}

// Note that the following will not work as long as top and stacklist are private
template <Class T>
void SwapStack2(Stack<T> &myS)
{
    T topItem;
    topItem= myS.Peek();
    myS.stacklist[top] = myS.stacklist[0];
    myS.stacklist[0] = topitem;
}

template <class T>
void showStackContent(Stack <T> MyS)
{
    while (!MyS.StackEmpty())
        cout<<MyS.Pop()<<endl;
}

template <class T>
void showQueueContent(Queue <T> MyQ)
{
    cout<<"The queue content is: ";
    while (!MyQ.QEmpty())
        cout<<" "<<MyQ.QDelete()<<" ";
    cout<<endl;

}

int main()
{
    /* Q1 CODE */ cout<<"QUESTION I\n";
    int userInputSize0;
    cout << "Enter the # of integers you will provide as queue: ";
    cin >> userInputSize0;
    Queue<int> Q0;
    int temp0;
    for(int i=1; i<=userInputSize0; i++)
    {
        cout << "Enter the integer #"<<i<<": ";
        cin >> temp0;
        Q0.QInsert(temp0);
    }
    int keyValue2;
    cout << "Enter the key which will be searched and deleted if it exists: ";
    cin >> keyValue2;

    cout<<"BEFORE SEARCH/DELETE"<<endl;
    showQueueContent(Q0);
    findinQ2(keyValue2, Q0);
    cout<<"AFTER SEARCH/DELETE"<<endl;
    showQueueContent(Q0);

    /* Q2 CODE */ cout<<"QUESTION II\n";
    int intBin;
    cout << "Enter the integer to evaluate the binary version: ";
    cin >> intBin;
    cout<<"Binary representation of "<<intBin<<" is ";
    printBinary(intBin);

    /* Q3 CODE */ cout<<"QUESTION III\n";
    cout<<"The original queue"<<endl;
    showQueueContent(Q0);
    reverseQueue(Q0);
    cout<<"The reversed queue"<<endl;
    showQueueContent(Q0);

    /* Q4 CODE */ cout<<"QUESTION IV\n";

    int userInputSize1;
    cout << "Enter the # of integers you will provide as stack: ";
    cin >> userInputSize1;
    Stack<int> S1;
    int temp1;
    for(int i=1; i<=userInputSize1; i++)
    {
        cout << "Push the integer #"<<i<<" into the stack: ";
        cin >> temp0;
        S1.Push(temp0);
    }

    cout<<"The original stack content:"<<endl;
    showStackContent(S1);
    cout<<"The swapped stack content:"<<endl;
    SwapStack(S1);
    showStackContent(S1);

    return 0;
}

