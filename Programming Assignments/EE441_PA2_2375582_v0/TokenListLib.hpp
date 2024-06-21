/*

#ifndef TOKENLISTLIB_HPP_INCLUDED
#define TOKENLISTLIB_HPP_INCLUDED
#include <iostream>
#include "TokenList.hpp"
using namespace std;
// Traversing a linked list

void ShowList(TokenList*&head)
{
    int pos=0;
    TokenList*currPtr=head;
    if(currPtr==NULL)
        cout<<"the list is empty\n";
    while(currPtr!=NULL)
    {
        cout<<"current list position: "<<pos<<endl;
        currPtr->data.Info();
        //what is the potential problem to print out the data?
        currPtr = currPtr->NextNode();
        pos++;
    }
}
// create a new node, i.e., allocate a node with data member item and pointer nextPtr

TokenList *GetNode(const Token& item, TokenList *ptrnext = NULL)
{
    TokenList *newNode;
    newNode = new TokenList(item,ptrnext);

    /*allocate memory and pass item and ptrnext to the constructor which creates the object */

    //terminate program if allocation not successful
/*
    if (newNode==NULL)
    {
        cerr<<"Memory allocation failed"<<endl;
        exit(1);
    }

    return newNode;
}

/*int Find(TokenList *head, Token& item, TokenList* &prevPtr)
{
    TokenList *currentPtr   = head;
    prevPtr                 = NULL;

    while(currentPtr != NULL)
    {
        if(currentPtr->data == item)
        {
            item = currentPtr->data;
            return 1;
        }
        prevPtr = currentPtr;
        currentPtr = currentPtr->NextNode();
    }
}
*/
/*/*
void InsertFront(TokenList* & head, Token item)
/* we are passing in the address of the head pointer by &head so that it can be modified */
/*{
/* allocate new node so that it points to the first item in the original list,
and updated head pointer to point to the new node */
 /*   head=GetNode(item,head);
}
#endif // TOKENLISTLIB_HPP_INCLUDED
*/
