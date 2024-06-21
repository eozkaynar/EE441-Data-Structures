
#include <iostream>
#include "TokenNew.hpp"
#include "TokenListNew.hpp"
#include "TokenListLib.hpp"
#include "Node.hpp"
#include "Treelib.hpp"
#include <string>
#include <string.h>
using namespace std;

Token* Lexer(const string &str)
{
    Token *head = NULL;
    TokenList* ptr = new TokenList (head);
    for(string::size_type i = 0; i < str.size(); ++i)
    {
        // Passing condition
        if(str[i]==' ')
            continue;
        else
            switch (str[i])
            {
                case '+':
                {
                    //OperatorToken ot1(addition,type_operator);
                    ptr->createTokenList(new OperatorToken(addition,type_operator));
                    break;
                }


                case '-':
                {
                    OperatorToken ot2(subtraction,type_operator);
                    ptr->createTokenList(new OperatorToken(subtraction,type_operator));

                    break;
                }
                case '*':
                {
                    OperatorToken ot3(multiplication,type_operator);
                    ptr->createTokenList(new OperatorToken(multiplication,type_operator));
                    break;
                }
                case '/':
                {
                    OperatorToken ot4(division,type_operator);
                    ptr->createTokenList(new OperatorToken(division,type_operator));

                    break;
                }
                default:
                {
                    double number = static_cast<double>(static_cast<int>(str[i] - '0'));
                    NumberToken nt(number,type_number);
                    ptr->createTokenList(new NumberToken(number,type_number));

                }


            }
    }
    return head;
}

int main()
{
    Token *head = NULL;
    Node *p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9;
/*

    p2 = GetNumberNode(5);
    p3 = GetNumberNode(2);
    p1 = GetOperatorNode(addition,p2,p3);
    p4 = GetNumberNode(7);
    p5 = GetNumberNode(1);
    p6 = GetOperatorNode(subtraction,p4,p5);
    p7 = GetOperatorNode(multiplication,p1,p6);
    p8 = GetNumberNode(4);
    p9 = GetOperatorNode(subtraction,p7,p8);
    //c = GetTreeNode('C',e, (TreeNode<char> *)NULL);
    //a = GetTreeNode('A',b, c);
    Preorder(p9);
    */

/*
    Token t(type_operator);
    InsertFront(head,t);
    OperatorToken ot('+',type_operator);
    InsertFront(head,ot);
    ot.Info();
    NumberToken nt('+',type_number);
    InsertFront(head,nt);
    nt.Info();
    TokenList node(*head);
    ShowList(head);
    cout<<ot.GetOperator();
*/
    string str = "5 2 6 * / 2 *";
    head = Lexer(str);
    ShowList(head);

    return 0;
}
