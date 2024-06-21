#ifndef TREE_SCANS
#define TREE_SCANS

#include "treenode.hpp"
#include "queue.hpp"
#include "stack.hpp"


#ifndef NULL
const int NULL = 0;
#endif    // NULL

// preorder recursive scan of the nodes in a tree
template <class T>
void Preorder (TreeNode<T> *t, void visit(T& item))
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      visit(t->data);               // visit the node
      Preorder<T> (t->Left(), visit);   // descend left
      Preorder<T> (t->Right(), visit);  // descend right
   }
}

// inorder recursive scan of the nodes in a tree
template <class T>
void InorderPrint (TreeNode<T> *t)
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      InorderPrint<T> (t->Left());	// descend left
      cout << t->data << "  ";					// visit the node
      InorderPrint<T> (t->Right());  // descend right
   }
}

// inorder recursive scan of the nodes in a tree
template <class T>
void Inorder (TreeNode<T> *t, void visit(T& item))
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      Inorder<T> (t->Left(), visit);	// descend left
      visit(t->data);						// visit the node
      Inorder<T> (t->Right(), visit);  // descend right
   }
}

// postorder recursive scan of the nodes in a tree
template <class T>
void Postorder (TreeNode<T> *t, void visit(T& item))
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      Postorder<T> (t->Left(), visit);  // descend left
      Postorder<T> (t->Right(), visit); // descend right
      visit(t->data);               // visit the node
   }
}

// traverse the list by level by level and visit each node
template <class T>
void LevelScan(TreeNode<T> *t, void visit(T& item))
{
   // store siblings of each node in a queue so that they are
   // visited in order at the next level of the tree
   Queue<TreeNode<T> *> Q;
   TreeNode<T> *p;  //temporary variable

   // initialize the queue by inserting the root in the queue
   Q.QInsert(t);

   // continue the iterative process until the queue is empty
   while(!Q.QEmpty())
   {
      // delete front node from queue and execute visit function
      p = Q.QDelete();
      visit(p->data);

      // if a left child exists, insert it in the queue
      if(p->Left() != NULL)
        Q.QInsert(p->Left());
      // if a right child exists, insert next to its sibling
      if(p->Right() != NULL)
       Q.QInsert(p->Right());
   }
}

#endif    // TREE_SCANS
