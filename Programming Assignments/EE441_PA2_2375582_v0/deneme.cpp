#include <iostream>
#include <sstream>

// Forward declaration of TokenList to resolve circular dependency
class TokenList;

// Token base class
class Token {
public:
    enum TokenType {
        Operator,
        Number
    };

    virtual TokenType getType() const = 0;
    virtual void setNext(Token* next) = 0;
    virtual Token* getNext() const = 0;

    virtual ~Token() {}
};

// OperatorToken derived from Token
class OperatorToken : public Token {
public:
    enum OperatorType {
        Addition,
        Subtraction,
        Multiplication,
        Division
    };

    OperatorToken(OperatorType op) : op(op), next(nullptr) {}

    TokenType getType() const override {
        return TokenType::Operator;
    }

    void setNext(Token* next) override {
        this->next = next;
    }

    Token* getNext() const override {
        return next;
    }

    OperatorType getOperator() const {
        return op;
    }

private:
    OperatorType op;
    Token* next;
};

// NumberToken derived from Token
class NumberToken : public Token {
public:
    NumberToken(double value) : value(value), next(nullptr) {}

    TokenType getType() const override {
        return TokenType::Number;
    }

    void setNext(Token* next) override {
        this->next = next;
    }

    Token* getNext() const override {
        return next;
    }

    double getValue() const {
        return value;
    }

private:
    double value;
    Token* next;
};

// TokenList class
class TokenList {
public:
    TokenList() : head(nullptr), tail(nullptr) {}

    ~TokenList() {
        deleteList();
    }

    void addToken(Token* token) {
        if (!head) {
            head = tail = token;
        } else {
            tail->setNext(token);
            tail = token;
        }
    }

    Token* getTokenAt(int index) const {
        Token* current = head;
        int currentIndex = 0;

        while (current) {
            if (currentIndex == index) {
                return current;
            }

            current = current->getNext();
            currentIndex++;
        }

        return nullptr; // Index out of bounds
    }

    // Add other necessary member functions like printList, deleteList, etc.

private:
    Token* head;
    Token* tail;

    void deleteList() {
        Token* current = head;

        while (current) {
            Token* next = current->getNext();
            delete current;
            current = next;
        }

        head = tail = nullptr;
    }
};

// Lexer function to tokenize a Polish Notation expression
TokenList lexer(const std::string& expression) {
    TokenList tokenList;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Operator token
            OperatorToken::OperatorType op;
            if (token == "+") op = OperatorToken::Addition;
            else if (token == "-") op = OperatorToken::Subtraction;
            else if (token == "*") op = OperatorToken::Multiplication;
            else if (token == "/") op = OperatorToken::Division;

            tokenList.addToken(new OperatorToken(op));
        } else {
            // Number token
            double number;
            std::istringstream(token) >> number;
            tokenList.addToken(new NumberToken(number));
        }
    }

    return tokenList;
}

int main() {
    // Example usage:
    std::string expression = "+ 5 2 - 7 1 4";
    TokenList tokenList = lexer(expression);

    // Print the token list
    // tokenList.printList();

    // Access a token at a specific index
    Token* token = tokenList.getTokenAt(4);
    if (token) {
        if (token->getType() == Token::TokenType::Number) {
            NumberToken* numToken = static_cast<NumberToken*>(token);
            std::cout << "Value at index 1: " << numToken->getValue() << std::endl;
        } else if (token->getType() == Token::TokenType::Operator) {
            OperatorToken* opToken = static_cast<OperatorToken*>(token);
            std::cout << "Operator at index 1" << std::endl;
        }
    } else {
        std::cout << "Index out of bounds" << std::endl;
    }

    return 0;
}
