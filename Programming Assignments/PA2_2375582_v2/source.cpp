#include <iostream>
#include <string>
#include <cmath>

enum class TypeToken {
    Operator,
    Number
};

enum class TypeOperator {
    Add,
    Subtract,
    Multiply,
    Divide
};

enum class TypeNode {
    OperatorNode,
    NumberNode
};

class Token {
protected:
    TypeToken type;

public:
    Token* next;  // Pointer to the next token

    virtual ~Token() {}
    Token(TypeToken t) : type(t), next(nullptr) {}
    TypeToken getType() const {
        return type;
    }
};

class OperatorToken : public Token {
private:
    TypeOperator opType;

public:
    OperatorToken(TypeOperator op) : Token(TypeToken::Operator), opType(op) {}
    TypeOperator getOpType() const {
        return opType;
    }
};

class NumberToken : public Token {
private:
    double number;

public:
    NumberToken(double num) : Token(TypeToken::Number), number(num) {}
    double getNumber() const {
        return number;
    }
};

class TokenList {
private:
    Token* head;

public:
    TokenList() : head(nullptr) {}

    ~TokenList() {
        Delete();
    }

    void InsertNode(Token* token) {
        if (!head) {
            head = token;
        } else {
            Token* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = token;
        }
    }

    void Delete() {
        while (head) {
            Token* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Token* getHead() const {
        return head;
    }
};

TokenList lexer(const std::string& input) {
    TokenList tokenList;
    size_t pos = 0;

    while (pos < input.length()) {
        std::string tokenString;
        while (pos < input.length() && input[pos] != ' ') {
            tokenString += input[pos];
            pos++;
        }

        if (!tokenString.empty()) {
            if (tokenString == "+") {
                tokenList.InsertNode(new OperatorToken(TypeOperator::Add));
            } else if (tokenString == "-") {
                tokenList.InsertNode(new OperatorToken(TypeOperator::Subtract));
            } else if (tokenString == "*") {
                tokenList.InsertNode(new OperatorToken(TypeOperator::Multiply));
            } else if (tokenString == "/") {
                tokenList.InsertNode(new OperatorToken(TypeOperator::Divide));
            } else {
                // Assume it's a number
                double number = std::stod(tokenString);
                tokenList.InsertNode(new NumberToken(number));
            }
        }

        // Move past the space
        pos++;
    }

    return tokenList;
}


// SYNTAX TREE & PARSER

// Base class Node
class Node {
public:
    virtual ~Node() {}
    virtual double getValue() const = 0;
    virtual void print() const = 0;
};

// Derived class OperatorNode
class OperatorNode : public Node {
private:
    TypeOperator opType;
    Node* leftOperand;
    Node* rightOperand;

public:
    OperatorNode(TypeOperator op, Node* left, Node* right) : opType(op), leftOperand(left), rightOperand(right) {}

    ~OperatorNode() {
        delete leftOperand;
        delete rightOperand;
    }

    double getValue() const override {
        double leftValue = leftOperand->getValue();
        double rightValue = rightOperand->getValue();

        switch (opType) {
            case TypeOperator::Add:
                return leftValue + rightValue;
            case TypeOperator::Subtract:
                return leftValue - rightValue;
            case TypeOperator::Multiply:
                return leftValue * rightValue;
            case TypeOperator::Divide:
                if (rightValue != 0) {
                    return leftValue / rightValue;
                } else {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return NAN; // Not a Number
                }
        }
        return 0; // Default return (this should never be reached)
    }

    void print() const override {
        std::cout << "(";
        leftOperand->print();
        switch (opType) {
            case TypeOperator::Add:
                std::cout << " + ";
                break;
            case TypeOperator::Subtract:
                std::cout << " - ";
                break;
            case TypeOperator::Multiply:
                std::cout << " * ";
                break;
            case TypeOperator::Divide:
                std::cout << " / ";
                break;
        }
        rightOperand->print();
        std::cout << ")";
    }
};

// Derived class NumberNode
class NumberNode : public Node {
private:
    double value;

public:
    NumberNode(double val) : value(val) {}

    double getValue() const override {
        return value;
    }

    void print() const override {
        std::cout << value;
    }
};

// Token classes (unchanged from previous code)

// TokenList class (unchanged from previous code)

// SyntaxTree class with the added print member function
class SyntaxTree {
private:
    Node* root;

public:
    SyntaxTree(Node* r) : root(r) {}

    ~SyntaxTree() {
        delete root;
    }

    double evaluate() const {
        if (root) {
            return root->getValue();
        } else {
            std::cerr << "Error: Empty syntax tree." << std::endl;
            return NAN; // Not a Number
        }
    }

    void print() const {
        if (root) {
            root->print();
        } else {
            std::cerr << "Error: Empty syntax tree." << std::endl;
        }
    }
};

Node* parseExpression(Token*& currentToken);
SyntaxTree parse(TokenList& tokens);
void calculate(const std::string& expression);

// Helper function to parse expressions
Node* parseExpression(Token*& currentToken) {
    if (!currentToken) {
        return nullptr;
    }

    if (currentToken->getType() == TypeToken::Operator) {
        TypeOperator opType = static_cast<OperatorToken*>(currentToken)->getOpType();
        currentToken = currentToken->next; // Move to the next token

        Node* leftOperand = parseExpression(currentToken);
        Node* rightOperand = parseExpression(currentToken);

        return new OperatorNode(opType, leftOperand, rightOperand);
    } else if (currentToken->getType() == TypeToken::Number) {
        double number = static_cast<NumberToken*>(currentToken)->getNumber();
        currentToken = currentToken->next; // Move to the next token

        return new NumberNode(number);
    }

    return nullptr;
}

// Step 8: Write a parse function
SyntaxTree parse(TokenList& tokens) {
    Token* currentToken = tokens.getHead();
    if (!currentToken) {
        std::cerr << "Error: Empty token list." << std::endl;
        return SyntaxTree(nullptr);
    }

    return SyntaxTree(parseExpression(currentToken));
}


void calculate(const std::string& expression) {
    TokenList tokens = lexer(expression);

    // Assuming the expression is always valid for simplicity in this example
    SyntaxTree syntaxTree = parse(tokens);

    std::cout << "Polish Notation: " << expression << std::endl;
    std::cout << "Infix Expression: ";
    syntaxTree.print();
    std::cout << " = " << syntaxTree.evaluate() << std::endl;
}





int main() {
    // Test 1: Basic arithmetic expression
    std::string expression1 = "+ 5 2";
    calculate(expression1);

    // Test 2: More complex expression
    std::string expression2 = "- * 3 + 4 2 -61";
    calculate(expression2);

    // Test 3: Division by zero (error case)
    std::string expression3 = "/ 5 0";
    calculate(expression3);

    // Test 4: Empty expression (error case)
    std::string expression4 = "";
    calculate(expression4);

    return 0;
}




