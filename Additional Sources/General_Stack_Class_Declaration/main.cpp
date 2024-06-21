#include <iostream>
#include "stack.hpp"

using namespace std;

int main()
{
    Stack<char>S;
    char palstring[80], deblankedstring[80],c;
    int i = 0; // string pointer
    bool ispalindrome = true; // it will stop if false

    // get input
    cout << "Enter a string:" << endl;
    cin.getline(palstring,80,'\n');
    // remove blanks
    Deblank(palstring,deblankedstring);
    i = 0;
    while(deblankedstring[i] != '\0')
    {
        S.Push(deblankedstring[i]);
        i++;
    }
    i = 0;
    while(!S.StackEmpty())
    {
        c = S.Pop();
        // get out of loop when first nonmatch
        if(c != deblankedstring[i])
        {
            ispalindrome = false;
            break;
        }
        i++;
    }
    if (ispalindrome)
        cout<<"\\" << palstring << "\\" << "is a palindrome" << endl;
    else
        cout<<"\\" << palstring << "\\" << "is not a palindrome" << endl;

    return 0;
 }
