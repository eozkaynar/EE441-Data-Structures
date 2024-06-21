#ifndef LIBS_HPP_INCLUDED
#define LIBS_HPP_INCLUDED



TokenList Lexer(const string &str) {
    /* This code based on this reference https://favtutor.com/blogs/split-string-cpp */

    // Define a new token list to add new elements
    TokenList tokenlist;
    // Define a string to split the string
    string currentToken;

    // Traverse in string
    for (char c : str) {
        // Check if character is delimeter or not
        if (c != ' ') {
            // Append the character to the current token string
            currentToken += c;
        } else {
            // Check token string
            if (!currentToken.empty())
            {
                // Create TokenList
                if (currentToken == "+")
                    tokenlist.createTokenList(new OperatorToken(addition, type_operator));

                else if (currentToken == "-")
                    tokenlist.createTokenList(new OperatorToken(subtraction, type_operator));

                else if (currentToken == "*")
                    tokenlist.createTokenList(new OperatorToken(multiplication, type_operator));

                else if (currentToken == "/")
                    tokenlist.createTokenList(new OperatorToken(division, type_operator));

                else
                {
                    double number = stod(currentToken);
                    tokenlist.createTokenList(new NumberToken(number, type_number));
                }
                // Clear the current token for the next splitted string
                currentToken = "";
            }
        }
    }

    // Process the last token if not empty
    if (!currentToken.empty())
    {
        if (currentToken == "+")
            tokenlist.createTokenList(new OperatorToken(addition, type_operator));

        else if (currentToken == "-")
            tokenlist.createTokenList(new OperatorToken(subtraction, type_operator));

        else if (currentToken == "*")
            tokenlist.createTokenList(new OperatorToken(multiplication, type_operator));

        else if (currentToken == "/")
            tokenlist.createTokenList(new OperatorToken(division, type_operator));
        else
        {
            double number = stod(currentToken);
            tokenlist.createTokenList(new NumberToken(number, type_number));
        }
    }

    return tokenlist;
}
// Parser function that takes head of TokenList and returns tree Node
Node* parserMain(Token* &TokenListPtr)
{
   // Token* head = tokenList;
    Operator NodeOperator;
    // Base Case
    if (TokenListPtr == NULL)
    {
        return nullptr;
    }
    // Get type of the TokenList
    Type type = TokenListPtr->GetType();
    // If the Token is OperatorToken
    if(!type)
    {
        // Get Operator
        Operator Op = TokenListPtr->GetOperator();
        // Assign Node Operator
        switch(Op)
        {
            case 0:
            {
                NodeOperator = addition;
                break;
            }
            case 1:
            {
                NodeOperator = subtraction;
                break;
            }
            case 2:
            {
                NodeOperator = multiplication;
                break;
            }
            case 3:
            {
                NodeOperator = division;
                break;
            }
            default:
            {
                cout << "Unknown operator code: " << Op << endl;
                return nullptr;
            }
        }

        // Update List element if it's not nullptr
        if (TokenListPtr->NextNode() != nullptr)
        {
            // Update List pointer
            TokenListPtr    = TokenListPtr->NextNode();
            //Recursion
            Node* NodeLeft  = parserMain(TokenListPtr);
            Node* NodeRight = parserMain(TokenListPtr);
            // Create a new tree node
            Node* newNode   = new OperatorNode(NodeOperator,NodeLeft,NodeRight);

        return newNode;
        }
        else
            return nullptr;
    }
    else
    {
        double number       = TokenListPtr->GetValue();
        // Update List pointer
        TokenListPtr        = TokenListPtr->NextNode();
        // Return new tree NumberNode
        return new NumberNode(number);
    }

    return nullptr;
}

// Parser function that takes TokenList reference and returns SyntaxTree
SyntaxTree parser(TokenList& tokens) {
    // Get head of TokenList
    Token* head = tokens.GetHead();
    // Check if the List is empty
    if (!head) {
        return SyntaxTree(nullptr);
    }
    // Call parserMain function
    return SyntaxTree(parserMain(head));
}



#endif // LIBS_HPP_INCLUDED
