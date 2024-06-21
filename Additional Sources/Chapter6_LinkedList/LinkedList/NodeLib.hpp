#ifndef NODELIB_HPP_INCLUDED
#define NODELIB_HPP_INCLUDED

#include <iostream>
using namespace std;

#include "Node.hpp"

// create a new node, i.e., allocate a node with data member item and pointer nextPtr
template <class T>
Node<T> *GetNode(const T& item, Node<T> *ptrnext = NULL)
{
    Node<T> *newNode;
    newNode = new Node<T>(item,ptrnext);

    /*allocate memory and pass item and ptrnext to the constructor which creates the object */

    //terminate program if allocation not successful

    if (newNode==NULL)
    {
        cerr<<"Memory allocation failed"<<endl;
        exit(1);
    }

    return newNode;
}
template <class T>
int Find(Node<T> *head, T& item, Node<T>* &prevPtr)
{
    Node<T> *currentPtr = head;
    prevPtr             = NULL;

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
template <class T>
void InsertFront(Node<T>* & head, T item)
/* we are passing in the address of the head pointer by &head so that it can be modified */
{
/* allocate new node so that it points to the first item in the original list,
and updated head pointer to point to the new node */
    head=GetNode(item,head);
}
template <class T>
void InsertRear(Node<T>* & head, const T& item)
{
    Node<T> *newNode, *currPtr = head;
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

// Traversing a linked list
template <class T>
void ShowList(Node<T>*&head)
{
    int pos=0;
    Node<T>*currPtr=head;
    if(currPtr==NULL)
        cout<<"the list is empty\n";
    while(currPtr!=NULL)
    {
        cout<<"current list position: "<<pos<<" - data: "<<currPtr->data<<endl;
        //what is the potential problem to print out the data?
        currPtr = currPtr->NextNode();
        pos++;
    }
}
#endif // NODELIB_HPP_INCLUDED
