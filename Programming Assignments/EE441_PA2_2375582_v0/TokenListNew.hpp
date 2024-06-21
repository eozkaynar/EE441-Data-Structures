#ifndef TOKENLISTNEW_HPP_INCLUDED
#define TOKENLISTNEW_HPP_INCLUDED

#include <iostream>
#include "TokenNew.hpp"
using namespace std;
// Traversing a linked list

class TokenList
{
    private:
    public:
        Token *head;
        TokenList(Token* &ptr):head(ptr)
        {}
        TokenList createTokenList(Token* tokenPtr);

};

TokenList TokenList::createTokenList(Token* tokenPtr)
{
    Token *newNode, *currPtr = head;
    if(head == NULL)
        head = tokenPtr;
    else
    {
        while (currPtr->NextNode() != NULL)
            currPtr = currPtr->NextNode();

        currPtr->InsertAfter(tokenPtr);
    }

}

void ShowList(Token *&head)
{
    int pos=0;
    Token *currPtr=head;
    if(currPtr==NULL)
        cout<<"the list is empty\n";
    while(currPtr!=NULL)
    {
        cout<<"current list position: "<<pos<<endl;
        if(!currPtr->GetType())
        {
            std::cout << "Operator Token: ";
            switch (static_cast<int>(currPtr->GetValue())) {
                case 0:
                    std::cout << "+"<<endl;;
                    break;
                case 1:
                    std::cout << "-"<<endl;;
                    break;
                case 2:
                    std::cout << "*"<<endl;;
                    break;
                case 3:
                    std::cout << "/"<<endl;;
                    break;
                }
        }
        else
        {
                cout <<currPtr->GetValue()<<endl;
        }
        currPtr = currPtr->NextNode();
        pos++;
    }
}
// create a new node, i.e., allocate a node with data member item and pointer nextPtr

Token *GetOperatorToken(Operator &item,Type t ,Token *ptrnext = NULL)
{
    Token *newNode;
    newNode = new OperatorToken(item,t,ptrnext);

    /*allocate memory and pass item and ptrnext to the constructor which creates the object */

    //terminate program if allocation not successful

    if (newNode==NULL)
    {
        cerr<<"Memory allocation failed"<<endl;
        exit(1);
    }

    return newNode;
}

Token *GetNumberToken(double &item,Type t, Token *ptrnext = NULL)
{
    Token *newNode;
    newNode = new NumberToken(item,t,ptrnext);

    /*allocate memory and pass item and ptrnext to the constructor which creates the object */

    //terminate program if allocation not successful

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

void InsertFront(Token* & head,Type t, double &item)
/* we are passing in the address of the head pointer by &head so that it can be modified */
{
/* allocate new node so that it points to the first item in the original list,
and updated head pointer to point to the new node */
    head=GetNumberToken(item,t,head);
}

void InsertFront(Token* & head,Type t, Operator &item)
/* we are passing in the address of the head pointer by &head so that it can be modified */
{
/* allocate new node so that it points to the first item in the original list,
and updated head pointer to point to the new node */
    head=GetOperatorToken(item,t,head);
}

/*
void InsertRear(Token* &head, const double item)
{
    Token *newNode, *currPtr = head;
    if (currPtr == NULL)
    {
        InsertFront(head,item);
    }
    else
    {
        while (currPtr->NextNode() != NULL)
            currPtr = currPtr->NextNode();

        newNode = GetNode(item);
        currPtr->InsertAfter(newNode);
    }

}
void InsertRear(Token* &head, const Operator item)
{
    Token *newNode, *currPtr = head;
    if (currPtr == NULL)
    {
        InsertFront(head,item);
    }
    else
    {
        while (currPtr->NextNode() != NULL)
            currPtr = currPtr->NextNode();

        newNode = GetNode(item);
        currPtr->InsertAfter(newNode);
    }

}
/*
// Deleting a node at the front of a linked list
template <class T>
void DeleteFront(Node<T>* & head)
{
    Node<T> *p = head;
    if(head != NULL)
    {
        head = head->NextNode();
        delete p;
    }
}

// delete the first occurrence of key in the list
template <class T>
void Delete(Node <T>* &head, T key)
{
    Node<T> *currPtr = head, *prevPtr = NULL;
        // return if the list is empty
    if (currPtr==NULL)
        return;
    // cycle list until key is located or come to end
    while(currPtr !=NULL && currPtr->data!=key)
    {   // advance currPtr so prevPtr trails it
        prevPtr=currPtr; //keep prev item to delete next
        currPtr=currPtr->NextNode();
    }
    if (currPtr!=NULL) //i.e. keyfound
    {
        if (prevPtr==NULL) //i.e key found at first entry
            head=head->NextNode();
        else
            // match occurred at 2nd or subsequent node
            // prevPtr->DeleteAfter() unlinks the node
            prevPtr->DeleteAfter();//note that we return address of the deleted node but no delete operation
        delete currPtr; //remove memory space to memory manager
    }
}
// insert an item into the ordered list
template <class T>
void InsertOrder(Node<T>* & head, T item)
{
    // currPtr moves through list, trailed by prevPtr
    Node<T> *currPtr, *prevPtr, *newNode;
        // prevPtr == NULL signals match at front
	prevPtr = NULL;
    currPtr = head;

    // cycle through the list and find insertion point
    while (currPtr != NULL)
    {

        if(item<currPtr->data)
            break;
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
    }
    if (prevPtr == NULL)
        InsertFront(head,item);
    else
    {
        newNode = GetNode(item);
        prevPtr->InsertAfter(newNode);
    }

}
// delete all the nodes in the linked list
template <class T>
void ClearList(Node<T> * &head)
{
    Node<T> *currPtr, *nextPtr;

	// chain through the list deleting nodes
    currPtr = head;
    while(currPtr != NULL)
    {
	// record address of next node, delete current node
        nextPtr = currPtr->NextNode();
        delete currPtr;

        // move current node forward
        currPtr = nextPtr;
    }

    // mark list as empty
    head = NULL;
}


#endif // TOKENLISTLIB_HPP_INCLUDED
*/

#endif // TOKENLISTNEW_HPP_INCLUDED
