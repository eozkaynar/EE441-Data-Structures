#include <iostream>
using namespace std;

#include "treelib.hpp"
#include "treenode.hpp"
#include "treescan.hpp"
#include "treeprnt.hpp"

#ifndef NULL
const int NULL = 0;
#endif  // NULL

int FindKey(TreeNode<int> *MyTree, int key)
{
    if(MyTree == NULL)
    { // if the subtree is empty -> key was not found
        return -1;
    }
    else
    {// There is still a chance
        if(MyTree->data == key)
        {// current node has key -> return its pointer
            return 0;
        }
        else
        {// current node does not have the key, check sub-trees
            if (MyTree->Left() == NULL && MyTree->Right() == NULL)
            {// no more chance
                return -1;
            }
            else
            {// check the next level depending on the comparison of the current node's data and the key
                int level;
                if(MyTree->data > key)// node with key must be on the left
                    level = FindKey(MyTree->Left(),key);
                else // node with the key must be on the right
                    level = FindKey(MyTree->Right(),key);
                if(level < 0)
                    return -1;
                else
                    return level + 1;
            }
        }
    }
}

template <class T>
int TSum(TreeNode<T> *t)
{
    int sumLeft, sumRight, sum;
    if (t==NULL)
        sum=0; // if empty, sum=0
    else
    {
        sumLeft=TSum(t->Left());
        sumRight=TSum(t->Right());
        sum=t->data+sumLeft+sumRight;
    }
    return sum;
}

void TSumLess(TreeNode<int> *MyTree, int key, int &lessSum)
{
    if (MyTree!=NULL)
    {
        if(MyTree->data==key)
        {
            lessSum += MyTree->data + TSum(MyTree->Left());
            cout << "Sum of all items that are smaller than or equal to " << key << " is " << lessSum << endl;
            return;
        }
        else
        {
            if(MyTree->Left()==NULL&& MyTree->Right()==NULL)
                return;
            else if(MyTree ->data>key) // if key is smaller, go to left
                TSumLess(MyTree ->Left(),key, lessSum);
            else
            { // if key is greater, go right and add the parent and the left child
                lessSum += MyTree->data + TSum(MyTree ->Left());
                TSumLess(MyTree->Right(), key, lessSum);
            }
        }
    }
}

int main()
{
    TreeNode<int> left31(8);
    TreeNode<int> right32(30);
    TreeNode<int> left33(54);
    TreeNode<int> left34(63);
    TreeNode<int> left21(20,&left31);
    TreeNode<int> right21(27,NULL,&right32);
    TreeNode<int> left22(57,&left33);
    TreeNode<int> right22(70,&left34);
    TreeNode<int> left1(25,&left21,&right21);
    TreeNode<int> right1(61,&left22,&right22);
    TreeNode<int> root(50,&left1,&right1);

    cout<<"Tree is printed horizontally:\n";
    PrintTree (&root, 0);
    cout<<"Tree is printed vertically:\n";
    PrintVTree (&root, 2, 40);

    int keyInt = 30;

    int keyLevel = FindKey(&root, keyInt);
    cout<< "\nSearch for " << keyInt;
    if (keyLevel==-1)
        cout << " and it cannot be found" << endl;
    else
        cout << " and the level is " << keyLevel << endl;

    cout <<"Sum of the elements in the tree are: " << TSum(&root) << endl;
    int lessSum=0;
    TSumLess(&root, keyInt, lessSum);

    return 0;
}
