#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

class Node
{
    protected:
        // Points to the left and right children of the node
        Node *left;
        Node *right;
    public:

        // constructor
        Node (Node *lptr = NULL, Node *rptr = NULL);

        // access methods for the pointer fields
        Node *Left(void) const;
        Node *Right(void) const;
        virtual double GetValue(void) const
        {
            return(0);
        }
};
//
//enum Operator{addition,subtraction,multiplication,division};
//
class OperatorNode: public Node
{
    private:
    public:
        // data
        Operator op;
        // constructor
        OperatorNode (const Operator &o,Node *lptr = NULL, Node *rptr = NULL);
        double GetValue (void) const
        {
            double l_operand = left->GetValue();
            double r_operand = right->GetValue();
            switch(op)
            {
                case 0:
                {
                    return l_operand+r_operand;
                    break;
                }
                case 1:
                {
                    return l_operand-r_operand;
                    break;
                }
                case 2:
                {
                    return l_operand*r_operand;
                    break;
                }
                case 3:
                {
                    return l_operand/r_operand;
                    break;
                }
                default:
                    break;
            }
        }

};

class NumberNode:public Node
{
    public:
        // data
        double number;
        //constructor
        NumberNode(const double &n,Node *lptr = NULL, Node *rptr = NULL);
        // Get Value
        double GetValue() const
        {
            return number;
        }

};





Node::Node(Node *lptr, Node *rptr):left(lptr),right(rptr)
{}

Node* Node::Left(void) const
{
    return left;
}
Node* Node::Right(void) const
{
    return right;
}

OperatorNode::OperatorNode(const Operator &o,Node *lptr, Node *rptr):op(o),Node(lptr,rptr)
{}


NumberNode::NumberNode(const double &n,Node *lptr, Node *rptr):number(n),Node(lptr,rptr)
{

}

#endif // NODE_HPP_INCLUDED

