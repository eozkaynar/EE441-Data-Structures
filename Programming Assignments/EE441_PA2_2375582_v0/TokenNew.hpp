#ifndef TOKENNEW_HPP_INCLUDED
#define TOKENNEW_HPP_INCLUDED


enum Operator{addition,subtraction,multiplication,division};
enum Type{type_operator,type_number};
// Token base class
class Token
{
    protected:
      Type type;
      Token *next;
    public:
        // Constructor
        Token(void);
        Token(const Type &t, Token *ptr = NULL)
        {
            type = t;
            next = ptr;
        }
        // Print info about token
        void Info() const;
        Type GetType() const;
        bool operator==(const Token &otherToken);

        void InsertAfter (Token* &p);
        Token *DeleteAfter(void);

        // Access to pointers
        Token *NextNode(void) const;
        virtual double GetValue(void) const
        {
            return(0);
        }


};


// Operator Token class
class OperatorToken:public Token{
    private:
        Operator operation;
    public:
        OperatorToken(Operator o,const Type &t, Token *ptr = NULL):operation(o),Token(t,ptr){}
        void Info() const;
        double GetValue (void) const
        {
            return operation;

        }
        bool operator==(const OperatorToken &otherToken);

};

// Number Token class
class NumberToken:public Token{
    private:
        double number;


    public:

        NumberToken(double n,const Type &t, Token *ptr = NULL):number(n),Token(t,ptr){}
        void Info() const;
        double GetValue() const
        {
            return number;
        }
        bool operator==(const NumberToken &otherToken);

};


void Token::InsertAfter(Token* &p)
{
    p->next = next;
    next = p;
}

Token *Token::DeleteAfter(void)
{
    Token *tempPtr = next;

    if(next == NULL)
        return NULL;

    next = tempPtr->next;
    return tempPtr;
}


Token *Token::NextNode(void) const
{
    return next;
}

#include <iostream>

using namespace std;
void Token::Info() const
{
    //Print type of the token
    cout<<"Type: ";
    if(type == type_operator)
        cout<<"Operator"<<endl;
    else
        cout<<"Number"<<endl;
}

Type Token::GetType() const
{
    return type;
}

bool Token::operator==(const Token &otherToken)
{
    return type == otherToken.GetType();
}


void OperatorToken::Info() const
{
    //Print type of the token
    Token::Info();
    cout<<"Operator: "<<operation<< endl;

}
/*
Operator OperatorToken::GetOperator() const
{
    return operation;
}
*/
/*
bool OperatorToken::operator==(const OperatorToken &otherToken)
{
    return operation == otherToken.GetOperator();

}

void NumberToken::Info() const
{
    //Print type of the token
    Token::Info();
    cout<<"Number: "<<number<< endl;
}
/*
double NumberToken::GetNumber() const
{
    return number;
}
*//*
bool NumberToken::operator==(const NumberToken &otherToken)
{
    return number == otherToken.GetNumber();

}
*/

#endif // TOKENNEW_HPP_INCLUDED
