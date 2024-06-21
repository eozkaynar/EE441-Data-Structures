#ifndef SYNTAXTREE_HPP_INCLUDED
#define SYNTAXTREE_HPP_INCLUDED

#include "Node.hpp"

class SyntaxTree
{
    public:
        Node *root;
        // Constructor
        SyntaxTree(Node* r) : root(r) {}
        // Destructor
        ~SyntaxTree() {
            delete root;
        }
        // Print function to print tree
        void print() const;
        // Print final result
        void printResult() const;

};

void SyntaxTree::print()const
{   // check if tree is not empty
    if (root != nullptr)
        root->print();
    // Print final result
    printResult();
}

void SyntaxTree::printResult()const
{
    // check if tree is not empty
    if (root != nullptr)
        // Print value of root
        cout<<" = " <<root->GetValue();
}

#endif // SYNTAXTREE_HPP_INCLUDED
