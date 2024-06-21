#ifndef TOKENLIST_HPP_INCLUDED
#define TOKENLIST_HPP_INCLUDED

#include "Token.hpp"

class TokenList
{
    private:
        // Head of TokenList
        Token* head;
    public:
        //Constructor
        TokenList():head(nullptr){}
        //Destructor
        ~TokenList() {
            ClearList();
        }
        // Function for create a linklist
        void createTokenList(Token* tokenPtr);
        // Show a link list
        void ShowList();
        // Clear the list
        void ClearList();
        // Return head of linked list
        Token* GetHead() const
        {
            return head;
        }

};


// Function from lecture notes
void TokenList::ClearList()
{
    Token *currPtr, *nextPtr;
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
// Function for create a Tokenlist
void TokenList::createTokenList(Token* tokenPtr)
{
        Token* currPtr = head;
        // Check if TokenList is not empty
        if (!head) {
            // If it is empty add first element
            head  = tokenPtr;
        } else {
            // Add element in the end of the TokenList
            // Get the end of the TokenList
            while(currPtr->NextNode()!= NULL)
                currPtr = currPtr->NextNode();
            // Add new token end of the TokentList
            currPtr->InsertAfter(tokenPtr);
        }
}
void TokenList::ShowList()
{
    // Initialize position
    int pos=0;

    Token *currPtr = head;

    //Check  if the list empty
    while(currPtr!=NULL)
    {
        cout<<"current list position: "<<pos<<endl;
        if(!currPtr->GetType())
        {
            cout << "Operator Token: ";
            // Print the operator
            switch (static_cast<int>(currPtr->GetValue())) {
                case 0:
                    cout << "+"<<endl;;
                    break;
                case 1:
                    cout << "-"<<endl;;
                    break;
                case 2:
                    cout << "*"<<endl;;
                    break;
                case 3:
                    cout << "/"<<endl;;
                    break;
                }
        }
        else
        {       //Print the number
                cout << "Number Token: ";
                cout <<currPtr->GetValue()<<endl;
        }
        // Move the next node
        currPtr = currPtr->NextNode();
        // Increase the position
        pos++;
    }
}

#endif // TOKENLIST_HPP_INCLUDED
