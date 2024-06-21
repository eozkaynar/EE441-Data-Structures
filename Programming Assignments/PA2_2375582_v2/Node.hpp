#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

class Node
{
    protected:
        // Points to the left and right children of the node
        Node *left;
        Node *right;
    public:

        // Constructor
        Node (Node *lptr = NULL, Node *rptr = NULL);

        // access methods for the left and write children
        Node *Left(void) const;
        Node *Right(void) const;

        // Definition of print method for polymorphism
        virtual void print() const  {
            return;
        }
        // Definition of method for polymorphism
        virtual double GetValue(void) const
        {
            return(0);
        }


};

class OperatorNode: public Node
{
    private:
        // data
        Operator op;
    public:

        // constructor
        OperatorNode (const Operator &o,Node *lptr = NULL, Node *rptr = NULL);
        // Return Node value
        double GetValue (void) const;
        // Print function for Tree
        void print(void) const;
        // Return Operator
        Operator GetOperator() const
        {
            return op;
        }
};

class NumberNode:public Node
{
    public:
        // data
        double number;
        //constructor
        NumberNode(const double &n,Node *lptr = NULL, Node *rptr = NULL):number(n),Node(lptr,rptr)
        {}
        // Get Value
        double GetValue() const
        {
            return number;
        }
        //print the holded number
        void print() const {
           cout << number;
        }

};
// Node class functions
//Constructor
Node::Node(Node *lptr, Node *rptr):left(lptr),right(rptr)
{}
// Return Left pointer
Node* Node::Left(void) const
{
    return left;
}
// Return Right pointer
Node* Node::Right(void) const
{
    return right;
}

// Operator Node functions
OperatorNode::OperatorNode(const Operator &o,Node *lptr, Node *rptr):op(o),Node(lptr,rptr)
{}

void OperatorNode::print(void) const
{
    // To  prints the expression in the conventional infix form
    // InOrder print should be used
    // Example Syntax String (*52)
    // print "(" , print left node ,print Node, print right node, print ")"
        cout << "(";

        // Print left node
        left->print();
        // print Node operator
        switch (op) {
            case 0:
                cout << " + ";
                break;
            case 1:
                cout << " - ";
                break;
            case 2:
                cout << " * ";
                break;
            case 3:
                cout << " / ";
                break;
        }
        // print right node
        right->print();
        cout << ")";
}

double OperatorNode::GetValue(void) const
{
    // value of left operand
    double l_operand = left->GetValue();
    // value of right operand
    double r_operand = right->GetValue();
    switch(op)
    {
        case 0:
        {
            // If Operator is addition
            return l_operand+r_operand;
            break;
        }
        case 1:
        {
            // If Operator is subtraction
            return l_operand-r_operand;
            break;
        }
        case 2:
        {
            // If Operator is multiplication
            return l_operand*r_operand;
            break;
        }
        case 3:
        {
            // If Operator is division
            return l_operand/r_operand;
            break;
        }
        default:
            break;
    }
}

#endif // NODE_HPP_INCLUDED
