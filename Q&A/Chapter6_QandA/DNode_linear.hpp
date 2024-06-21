#ifndef DOUBLY_LINEAR_LINKED_NODE_CLASS
#define DOUBLY_LINEAR_LINKED_NODE_CLASS

// You may want to check this code and correct possible implementation mistakes.
// Since this class copied from the DNode Class, which is Double Circular Linked List.
// There are some cases to be considered for Doubly Linear Linked List...

template <class T>
class DNode_linear
{
    private:
    	// circular links to the prev and next
        DNode_linear<T> *prev;
        DNode_linear<T> *next;
    public:
    	// data is public
        T data;

		// constructors
        DNode_linear(void);
        DNode_linear(const T& item);


        // list modification methods
        void InsertNext(DNode_linear<T> *p);
        void InsertPrev(DNode_linear<T> *p);
        DNode_linear<T> *DeleteNode(void);


        // obtain address of the next node to the prev or next
        DNode_linear<T> *NextNodeNext(void) const;
        DNode_linear<T> *NextNodePrev(void) const;
};

// constructor that creates an empty list and
// leaves the data uninitialized. use for header
template <class T>
DNode_linear<T>::DNode_linear(void)
{
	// initialize the node so it points to itself
    prev = NULL;
    next = NULL;
}

// constructor that creates an empty list and initializes data
template <class T>
DNode_linear<T>::DNode_linear(const T& item)
{
	// set node to point to itself and initialize data
    prev = NULL;
    next = NULL;
    data = item;
}

// insert a node p to the next of current node
template <class T>
void DNode_linear<T>::InsertNext(DNode_linear<T> *p)
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
void DNode_linear<T>::InsertPrev(DNode_linear<T> *p)
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
DNode_linear<T> *DNode_linear<T>::DeleteNode(void)
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
DNode_linear<T> *DNode_linear<T>::NextNodeNext(void) const
{
    return next;
}

// return pointer to the next node on the prev (left)
template <class T>
DNode_linear<T> *DNode_linear<T>::NextNodePrev(void) const
{
    return prev;
}

#endif	// DOUBLY_LINKED_NODE_CLASS
