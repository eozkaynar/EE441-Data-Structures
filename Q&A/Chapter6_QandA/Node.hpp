#ifndef NODE_CLASS
#define NODE_CLASS

template <class T>
class Node
{
    private:
		// next is the address of the following node
        Node<T> *next;
    public:
    	// the data is public
        T data;

		// constructor
        Node (const T& item, Node<T>* ptrnext = NULL);

        // list modification methods
        void InsertAfter(Node<T> *p);
        Node<T> *DeleteAfter(void);

        // obtain the address of the next node
        Node<T> *NextNode(void) const;

        // set the next node, but be careful, the original next node would be lost
        void SetNext(Node<T> *p);
};

// constructor. initialize data and pointer members
template <class T>
Node<T>::Node(const T& item, Node<T>* ptrnext) :
		 data(item), next(ptrnext)
{}

// return value of private member next
template <class T>
Node<T> *Node<T>::NextNode(void) const
{
    return next;
}

// insert a node p after the current one
template <class T>
void Node<T>::InsertAfter(Node<T> *p)
{
	if (p != NULL)
    {
        // p points to successor of the current node,
        // and current node points to p.
        p->next = next; //notice access to private part of member of same class
        next = p; //also note correct sequence of operation
    }
    else
        next = NULL;
}

// delete the node following current and return its address
template <class T>
Node<T> *Node<T>::DeleteAfter(void)
{
	// save address of node to be deleted
    Node<T> *tempPtr = next;

	// if there isn't a successor, return NULL
    if (next == NULL)
        return NULL;

	// current node points to successor of tempPtr.
	/*(i.e., delete next node by copying its nextptr to the
     nextptr of current node) */
    next = tempPtr->next;

	// return the pointer to the deleted node
    return tempPtr;
}

// set the next node, but be careful, the original next node would be lost
template <class T>
void Node<T>::SetNext(Node<T> *p)
{
    next = p;
}

#endif  // NODE_CLASS
