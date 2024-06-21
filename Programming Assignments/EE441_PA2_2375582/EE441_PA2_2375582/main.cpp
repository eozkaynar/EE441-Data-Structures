#include <iostream>
#include "Token.hpp"
#include "TokenList.hpp"
#include <string>
#include <string.h>
#include "Node.hpp"
#include "SyntaxTree.hpp"
#include "FunctionLib.hpp"

void Calculate (const string &str)
{
    // Tokenize function
    TokenList tlist = Lexer(str);
    // Create the appropriate tree structure for Polish Notation expressions
    SyntaxTree syntaxTree = parser(tlist);
    // Print with the conventional form and result
    syntaxTree.print();
}

using namespace std;

int main()
{
    // Polish Notation expression
    string str = " - * + 5 2 - 7 1 4";
    string str2 = " - * + -5 25 - 47 1.5 4";
    // Call Calculate function
    Calculate(str);
    Calculate(str2);

    return 0;
}
