#include <iostream>
using namespace std;

#include "Node.hpp"
#include "NodeLib.hpp"
#include "random.hpp"

int main ()
{
    /*
    //simple (but not efficient) code to check if there is memory leak in ClearList()
    Node<int> *tryHead = NULL;
    RandomNumber tryRnd;
    while(true)
    {
        int tempInt;
        for (int ii=0;ii < 100;ii++)
        {
            InsertFront(tryHead, int(1+tryRnd.Random(10)));
        }
        ClearList(tryHead);
    }
    */

    // set list head to NULL
    Node<int> *head = NULL, *currPtr;

    int i, key, count = 0;
    RandomNumber rnd;

    cout<<"First insert 5 random integers at the front of list"<<endl;
    int tempInt;
    for (i=0;i < 5;i++)
    {
        tempInt = int(1+rnd.Random(10));
        cout<<"Integer-"<<i+1<<" generated: "<<tempInt<<endl;
        InsertFront(head, tempInt);
    }

    // print the original list
    cout << "Content of the Linked-List: "<<endl;
    ShowList(head);
    cout << endl;

    cout<<"Now insert 5 random integers at the end of list"<<endl;
    for (i=0;i < 5;i++)
    {
        tempInt = int(1+rnd.Random(10));
        cout<<"Integer-"<<i+1<<" generated: "<<tempInt<<endl;
        InsertRear(head, tempInt);
    }

    // print the original list
    cout << "Content of the Linked-List: "<<endl;
    ShowList(head);
    cout << endl;

    cout<<"Delete the front element\n";
    DeleteFront(head);
    cout << "Content of the Linked-List: "<<endl;
    ShowList(head);
    cout << endl;

    // prompt user for an integer key
    cout << "Enter a key to find occurrences: ";
    cin >> key;

    // cycle through the list
    currPtr = head;
    while (currPtr != NULL)
    {
        // if data matches key, increment count
        if (currPtr->data == key)
            count++;

        // move to the next node of the list
        currPtr = currPtr->NextNode();
    }

    cout << "The data value " << key << " occurs " << count
         << " times in the list" << endl;

    // prompt user for an integer key
    cout << "Enter a key to find the first occurrence: ";
    cin >> key;
    Node<int>* tempPrvPtr;
    int ifFound = Find(head, key, tempPrvPtr);
    if (ifFound == 0)
        cout<<key<<" cannot be found in the list\n";
    else
        cout<<key<<" is found right after the element "<<tempPrvPtr->data<<endl;

    cout<<"Now we are deleting the first occurrence of the key "<<key<<"\n";
    Delete(head, key);
    cout << "Content of the Linked-List: "<<endl;
    ShowList(head);
    cout << endl;

    cout << "Clearing the Linked-List: "<<endl;
    ClearList(head);
    cout << "Content of the Linked-List: "<<endl;
    ShowList(head);
    cout << endl;

    for (i=0;i < 5;i++)
    {
        InsertRear(head, 3*i);
    }
    cout << "Content of the Linked-List: "<<endl;
    ShowList(head);
    cout << endl;

    for(int ii=0;ii<5;ii++)
    {
        cout << "Enter a key to insert in order: ";
        cin >> key;
        InsertOrder(head, key);
        cout << "Content of the Linked-List: "<<endl;
        ShowList(head);
        cout << endl;
    }

    return 0;
}


