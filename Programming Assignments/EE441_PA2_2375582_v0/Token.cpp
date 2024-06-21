/*
#include "Token.hpp"
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
char OperatorToken::GetOperator() const
{
    return operation;
}

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

double NumberToken::GetNumber() const
{
    return number;
}

bool NumberToken::operator==(const NumberToken &otherToken)
{
    return number == otherToken.GetNumber();

}
*/
