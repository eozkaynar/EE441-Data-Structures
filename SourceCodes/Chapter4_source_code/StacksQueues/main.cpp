// Assuming that the stack and queue declarations are in "Stack.hpp" and "Queue.hpp",
// and the implementations are in "Stack.cpp" and "Queue.cpp", respectively.

// Since we are using template classes, in order not to get a compiler error, we need to say explicitly which template classes
// we will be using. For doing so,
// - EITHER you can include the function implementations in the header file
// (equivalently you can include *.cpp files in your main file)
// - OR you should explicitly say compilers which template classes you will use.
// In our case, we choose the second option, which is not flexible though.
// For more information, please refer to
// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
using namespace std;

void Deblank(char *s, char *t)
{
    while (*s!='\0')
    {
        if (*s!=' ')
        {
            *t=*s;
            t++;
        }
        s++;
    }
    *t='\0'; //append NULL to new string
}

void findinQ(int key, Queue <int>& MyQ)
{
    Stack<int> S1;
    Stack<int> S2;
    int temp;
    while(!MyQ.QEmpty())
    {
        temp=MyQ.QDelete();
        if(temp!=key)
            S1.Push(temp);
    }
    while(!S1.StackEmpty())
        S2.Push(S1.Pop());

    while(!S2.StackEmpty())
        MyQ.QInsert(S2.Pop());
}

void showQueueContent(Queue <int>& MyQ)
{
    Queue<int> tempQ;
    int tempVal;
    int qSize = MyQ.QLength();
    cout<<"The queue content is: ";
    for(int i=0; i<qSize; i++)
    {
        tempVal = MyQ.QDelete();
        cout<<" "<<tempVal<<" ";
        tempQ.QInsert(tempVal);
    }
    cout<<endl;
    MyQ = tempQ;
}

int main()
{
    cout << "========================" << endl;
    cout << "======= Stacks =========" << endl;
    cout << "========================" << endl;

    // create stack object to store string in reverse order.
    Stack<char> S;
    char palstring[80] , deblankedstring[80] , c;
    int i=0; // string pointer
    bool ispalindrome=true; //we'll stop if false

    // get input
    cout << "Enter a string to check if it is a palindrome: " << endl;
    cin.getline(palstring,80,'\n');
    //remove blanks
    Deblank(palstring,deblankedstring);
    i=0;
    while(deblankedstring[i] != '\0')
    {
        S.Push(deblankedstring[i]);
        i++;
    }

    //now pop one-by-one comparing with original
    i=0;
    while (!S.StackEmpty())
    {
        c=S.Pop();
        //get out of loop when first nonmatch
        if (c!=deblankedstring[i])
        {
            ispalindrome=false;
            break;
        }
        // continue until the end of string
        i++;
    }

    //operation finished. Printout result
    if (ispalindrome)
        cout<<"\\"<<palstring<<"\\"<<"is a palindrome"<<endl;
    else
        cout<<"\\"<<palstring<<"\\"<<"is not a palindrome"<<endl;

    cout << "========================" << endl;
    cout << "======= Queues =========" << endl;
    cout << "========================" << endl;

    int userInputSize;
    cout << "Enter the # of integers you will provide as queue: ";
    cin >> userInputSize;

    Queue<int> Q;
    int temp;
    for(int i=1; i<=userInputSize; i++)
    {
        cout << "Enter the integer #"<<i<<": ";
        cin >> temp;
        Q.QInsert(temp);
    }

    cout<<"BEGINNING"<<endl;
    showQueueContent(Q);

    int keyValue;
    cout << "Enter the key which will be searched and deleted if it exists: ";
    cin >> keyValue;

    cout<<"BEFORE SEARCH/DELETE"<<endl;
    showQueueContent(Q);
    findinQ(keyValue, Q);
    cout<<"AFTER SEARCH/DELETE"<<endl;
    showQueueContent(Q);


    return 0;
}

