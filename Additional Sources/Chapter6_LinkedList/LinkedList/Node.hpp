#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
template <class T>

class Node
{
    private:
    Node<T> *next;
    public:
        T data;
    // Constructor
    Node (const T &item,Node<T> *ptrNext=NULL);
    // List modifications
    void InsertAfter (Node<T>* &p);
    Node<T> *DeleteAfter(void);

    // Access to pointers
    Node<T> *NextNode(void) const;

};

template <class T>
Node<T>::Node(const T &item,Node<T> *ptrNext):data(item),next(ptrNext)
{

}
template <class T>
void Node<T>::InsertAfter(Node<T>* &p)
{
    p->next = next;
    next = p;
}
template <class T>
Node<T> *Node<T>::DeleteAfter(void)
{
    Node<T> *tempPtr = next;

    if(next == NULL)
        return NULL;

    next = tempPtr->next;
    return tempPtr;
}

template <class T>
Node<T> *Node<T>::NextNode(void) const
{
    return next;
}

#endif // NODE_HPP_INCLUDED
