/*
#ifndef TOKENLIST_HPP_INCLUDED
#define TOKENLIST_HPP_INCLUDED
#include "Token.hpp"
#include <iostream>
class TokenList
{
    private:
        TokenList *next;
    public:
        Token data;
        // Constructor
        TokenList(const Token &item,TokenList *ptrNext=NULL);
        // List modifications
        void InsertAfter (TokenList* &p);
        TokenList *DeleteAfter(void);

        // Access to pointers
        TokenList *NextNode(void) const;
        bool operator==(const Token &otherToken);
};



#endif // TOKENLIST_HPP_INCLUDED
*/
