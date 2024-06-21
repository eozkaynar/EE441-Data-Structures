#ifndef DOUBLY_LINKED_NODE_CLASS
#define DOUBLY_LINKED_NODE_CLASS

template <class T>
class DNode
{
    private:
    	// circular links to the prev and next
        DNode<T> *prev;
        DNode<T> *next;
    public:
    	// data is public
        T data;

		// constructors
        DNode(void);
        DNode(const T& item);


        // list modification methods
        void InsertNext(DNode<T> *p);
        void InsertPrev(DNode<T> *p);
        DNode<T> *DeleteNode(void);


        // obtain address of the next node to the prev or next
        DNode<T> *NextNodeNext(void) const;
        DNode<T> *NextNodePrev(void) const;
};

// constructor that creates an empty list and
// leaves the data uninitialized. use for header
template <class T>
DNode<T>::DNode(void)
{
	// initialize the node so it points to itself
    prev = next = this;
}

// constructor that creates an empty list and initializes data
template <class T>
DNode<T>::DNode(const T& item)
{
	// set node to point to itself and initialize data
    prev = next = this;
    data = item;
}

// insert a node p to the next of current node
template <class T>
void DNode<T>::InsertNext(DNode<T> *p)
{
	// link p to its successor on the next
    p->next = next;
	next->prev = p;

 	// link p to the current node on its prev
    p->prev = this;
    next = p;
}

// insert a node p to the prev of current node
template <class T>
void DNode<T>::InsertPrev(DNode<T> *p)
{
	// link p to its successor on the prev
    p->prev = prev;
    prev->next = p;

 	// link p to the current node on its next
    p->next = this;
    prev = p;
}

// unlink the current node from the list and return its address
template <class T>
DNode<T> *DNode<T>::DeleteNode(void)
{
	// node to the prev must be linked to current node's next
    prev->next = next;

	// node to the next must be linked to current node's prev
    next->prev = prev;

    // return the address of the current node
    return this;
}

// return pointer to the next node on the next (right)
template <class T>
DNode<T> *DNode<T>::NextNodeNext(void) const
{
    return next;
}

// return pointer to the next node on the prev (left)
template <class T>
DNode<T> *DNode<T>::NextNodePrev(void) const
{
    return prev;
}

#endif	// DOUBLY_LINKED_NODE_CLASS
