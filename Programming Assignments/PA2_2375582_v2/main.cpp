#include <iostream>
#include "Token.hpp"
#include "TokenList.hpp"
#include <string>
#include <string.h>
#include "Node.hpp"
#include "SyntaxTree.hpp"
#include "Libs.hpp"

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
    string str = " - * + -5 2 - 7 1.5 24";

    // Call Calculate function
    Calculate(str);

    return 0;
}
