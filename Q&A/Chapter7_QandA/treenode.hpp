#ifndef TREENODE_CLASS
#define TREENODE_CLASS

#ifndef NULL
const int NULL = 0;
#endif  // NULL

// BinStree depends on TreeNode
template <class T>
class BinSTree;

// declares a tree node object for a binary tree
template <class T>
class TreeNode
{
   private:
      // points to the left and right children of the node
      TreeNode<T> *left;
      TreeNode<T> *right;

   public:
      // public member allowing the client to update its value
      T data;

      // constructor
      TreeNode (const T& item, TreeNode<T> *lptr = NULL,
                TreeNode<T> *rptr = NULL);

      // access methods for the pointer fields
      TreeNode<T>* Left(void) const;
      TreeNode<T>* Right(void) const;
};

// constructor. initialize the data and pointer fields.
// the pointer NULL assigns an empty tree
template <class T>
TreeNode<T>::TreeNode (const T& item, TreeNode<T> *lptr,
    TreeNode<T> *rptr): data(item), left(lptr), right(rptr)
{}

// method Left allows the user to reference the left child
template <class T>
TreeNode<T>* TreeNode<T>::Left(void) const
{
   // return the private member value left
   return left;
}

// method Left allows the user to reference the right child
template <class T>
TreeNode<T>* TreeNode<T>::Right(void) const
{
   // return the private member value right
   return right;
}
#endif // TREENODE_CLASS
