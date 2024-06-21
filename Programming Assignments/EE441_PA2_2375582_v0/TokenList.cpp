/*
#include "TokenList.hpp"
TokenList::TokenList(const Token &item,TokenList *ptrNext):data(item),next(ptrNext)
{

}

void TokenList::InsertAfter(TokenList* &p)
{
    p->next = next;
    next = p;
}

TokenList *TokenList::DeleteAfter(void)
{
    TokenList *tempPtr = next;

    if(next == NULL)
        return NULL;

    next = tempPtr->next;
    return tempPtr;
}


TokenList *TokenList::NextNode(void) const
{
    return next;
}
/*
bool TokenList::operator==(const Token &otherToken)
{
    if(data.GetType() == otherToken.GetType())
    {
        if(data.GetType() == 0)
        {
            return data.GetOperator() == otherToken.GetOperator();
        }
        else
            return data.GetNumber() == otherToken.GetNumber();
    }

}
*/
