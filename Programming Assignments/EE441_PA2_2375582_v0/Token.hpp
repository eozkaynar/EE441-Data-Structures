//#ifndef TOKEN_HPP_INCLUDED
//#define TOKEN_HPP_INCLUDED

/*
enum Type{type_operator,type_number};
// Token base class
class Token
{
    protected:
      Type type;
    public:
        // Constructor
        Token(void),
        Token(Type t)
        {
            type = t;
        }
        // Print info about token
        void Info() const;
        Type GetType() const;
        bool operator==(const Token &otherToken);

};

// Operator Token class
class OperatorToken:public Token{
    private:
        char operation;
    public:
        OperatorToken(char o,Type t):operation(o),Token(t){}
        void Info() const;
        char GetOperator() const;
        bool operator==(const OperatorToken &otherToken);

};

// Number Token class
class NumberToken:public Token{
    private:
        double number;


    public:
        NumberToken(double n,Type t):number(n),Token(t){}
        void Info() const;
        double GetNumber() const;
        bool operator==(const NumberToken &otherToken);

};

#endif // TOKEN_HPP_INCLUDED
*/
