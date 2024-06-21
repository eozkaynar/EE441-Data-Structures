#ifndef TOKEN_HPP_INCLUDED
#define TOKEN_HPP_INCLUDED

using namespace std;
// Operator class for operators
enum  Operator{addition,subtraction,multiplication,division};
// Differentiate operator type to number type
enum  Type{type_operator,type_number};
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
        virtual ~Token() {}

        // Print info about token
        void Info() const;

        // Return type of Token
        Type GetType() const;
        // List Node functions

        void InsertAfter (Token* &p);
        Token *DeleteAfter(void);

        // Access to pointers
        Token *NextNode(void) const;
        // Return value of number and operator as double
        virtual double GetValue(void) const
        {
            return(0);
        }
        // Return operator
        virtual Operator GetOperator(void) const
        {
            return(addition);
        }
};


// Operator Token class
class OperatorToken:public Token{
    private:
        Operator operation;
    public:
        // Constructor
        OperatorToken(const Operator &o,const Type &t, Token *ptr = NULL):operation(o),Token(t,ptr){}
        // Print Info
        void Info() const;
        // Return operator as double
        double GetValue (void) const;
        // Return type of node (operator or node)
        Type GetType() const;
        // Return Operator
        Operator GetOperator(void) const;
};


// Number Token class
class NumberToken:public Token{
    private:
        double number;
    public:
        // Constructor
        NumberToken(double &n,const Type &t, Token *ptr = NULL):number(n),Token(t,ptr){}
        // Print Info
        void Info() const;
        // Return the holded number
        double GetValue() const
        {
            return number;
        }
        // Return type of token
        Type GetType() const
        {
            return type_number;
        }

};

// Token class functions from lecture notes
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

// OperatorToken class functions
void OperatorToken::Info() const
{
    //Print type of the token
    Token::Info();
    cout<<"Operator: "<<operation<< endl;

}

double OperatorToken::GetValue() const
{
    switch(operation)
    {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;

    }
}

Type OperatorToken::GetType() const
{
    return type_operator;
}
Operator OperatorToken::GetOperator() const
{
    return operation;
}
#endif // TOKEN_HPP_INCLUDED
