#ifndef TREELIB_HPP_INCLUDED
#define TREELIB_HPP_INCLUDED
#include "Node.hpp"


Node *GetOperatorNode(Operator item, Node *lptr = NULL,
                         Node *rptr = NULL)
{
   Node *p;

   // call new to allocated the new node
   // pass parameters lptr and rptr to the function
   p = new OperatorNode (item, lptr, rptr);

   // if insufficient memory, exit with an error message
   if (p == NULL)
   {
      cerr << "Memory allocation failure!\n";
      exit(1);
   }

   // return the pointer to the system generated memory
   return p;
}

Node *GetNumberNode(double item, Node *lptr = NULL,
                         Node *rptr = NULL)
{
   Node *p;

   // call new to allocated the new node
   // pass parameters lptr and rptr to the function
   p = new NumberNode (item, lptr, rptr);

   // if insufficient memory, exit with an error message
   if (p == NULL)
   {
      cerr << "Memory allocation failure!\n";
      exit(1);
   }

   // return the pointer to the system generated memory
   return p;
}


void FreeNode(Node *p)
{
   delete p;
}

// using GetTreeNode, dynamically create three binary trees
// starting at the leaf nodes and stopping with the root node
// n is a parameter that selects from tree 0 - tree 2
/*void MakeCharTree(TreeNode<char>* &root, int n)
{
   // 9 TreeNode pointers; points to the 9 items in the tree
   TreeNode<char> *a, *b, *c, *d, *e, *f, *g, *h, *i;

   // parameter n specifies a tree in the range 0 - 2
   switch(n)
   {
      // nodes D and E leaf nodes ; A is root node
      case 0:
         d = GetTreeNode('D');
         e = GetTreeNode('E');
         b = GetTreeNode('B',(TreeNode<char> *)NULL, d);
         c = GetTreeNode('C',e, (TreeNode<char> *)NULL);
         a = GetTreeNode('A',b, c);
         root = a;
         break;

      // nodes E, G, H, and I leaf nodes ; A is root node
      case 1:
         g = GetTreeNode('G');
         h = GetTreeNode('H');
         i = GetTreeNode('I');
         d = GetTreeNode('D');
         e = GetTreeNode('E',g, (TreeNode<char> *)NULL);
         f = GetTreeNode('F',h, i);
         b = GetTreeNode('B',d, e);
         c = GetTreeNode('C',(TreeNode<char> *)NULL, f);
         a = GetTreeNode('A',b, c);
         root = a;
         break;

      // nodes F, G, H, and I leaf nodes ; A is root node
       case 2:
         g = GetTreeNode('G');
         h = GetTreeNode('H');
         i = GetTreeNode('I');
         d = GetTreeNode('D',(TreeNode<char> *)NULL, g);
         e = GetTreeNode('E',h, i);
         f = GetTreeNode('F');
         b = GetTreeNode('B',d, (TreeNode<char> *)NULL);
         c = GetTreeNode('C',e, f);
         a = GetTreeNode('A',b, c);
         root = a;
         break;
   }
}
*/
void PrintItem(double item)
{
    cout << item << "  ";
}

void PrintItem(char item)
{
    cout << item << "  ";
}
/*
void Postorder (Node *t, void PrintItem(T& item))
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      Postorder<T> (t->Left(), visit);  // descend left
      Postorder<T> (t->Right(), visit); // descend right
      visit(t->data);               // visit the node
   }
}

*/
void Preorder (Node *t)
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      cout<<t->GetValue()<<endl;// the node
      Preorder (t->Left());  // descend left
      Preorder (t->Right()); // descend right

   }
}

#endif // TREELIB_HPP_INCLUDED
