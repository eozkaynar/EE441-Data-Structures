#include <iostream>
using namespace std;

#include "treelib.hpp"
#include "treenode.hpp"
#include "treescan.hpp"
#include "treeprnt.hpp"

int main ()
{
    TreeNode<char> *t;
    t=GetTreeNode('a', GetTreeNode('b', (TreeNode<char> *) NULL, GetTreeNode('c')), GetTreeNode('d', GetTreeNode('e')));
    cout<<"Tree is printed horizontally:\n";
    PrintTree (t, 0);
    cout<<"Tree is printed vertically:\n";
    PrintVTree (t, 2, 40);

    cout<<"\nIn-order traversal print:\n";
    InorderPrint(t);

    cout<<"\nIn-order traversal and print:\n";
    Inorder(t,PrintItem);

    cout<<"\nIn-order traversal, change to upper-case, and print:\n";
    Inorder(t,UpperCase);
    Inorder(t,PrintItem);

    cout<<"\nIn-order traversal, change to lower-case,and print:\n";
    Inorder(t,LowerCase);
    Inorder(t,PrintItem);

    int noOfLeaf = 0;
    CountLeaf(t, noOfLeaf);
    cout<<"\nNumber of leaves is "<<noOfLeaf<<endl;

    cout<<"The depth of the tree is "<<Depth(t)<<endl;

    cout<<"the min key value is "<<minVal(t)<<endl;

    cout<<"the min leaf level is "<<minLeafDepth(t)<<endl;

    return 0;
}
