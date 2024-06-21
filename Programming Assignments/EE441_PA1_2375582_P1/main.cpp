#include "operation_queue.hpp"
#include <iostream>
#include <ostream>

using namespace std;

double apply_operations(OperationQueue &myQ,double input)
{
    Operation temp;
    while (!myQ.QEmpty())
    {
        // pop the front element of queueu
        temp = myQ.Pop_Front();
        // apply operation one by one
        input = temp.apply_operation(input);
    }
    return input;

}


int main()
{

    double x = 13.7;
    Operation op1(1.5,'+'), op2(2,'^'), op3(7.0/12,'-'), op4(3,'*');
    OperationQueue Q1;
    Q1.Push_Back(op1);
    Q1.Push_Back(op2);
    Q1.Push_Back(op3);
    Q1.Push_Back(op4);


    cout<< apply_operations(Q1,x)<<endl;

    return 0;
}
