#include <iostream>
using namespace std;

int i=0;

class A
{
    public:
        ~A()
        {
            i=i+1;
        };
};

int func1()
{
    i=i+1;
    {
        A obj1;
    }
    return i;
}

int func2()
{
    i=i+1;
    A obj2;
    return i;
}

int main()
{
    cout<<"at the beginning i = "<<i<<endl;
    cout<<"call func1, i = "<<func1()<<endl;
    cout<<"after calling func1 i = "<<i<<endl;
    cout<<"call func2, i = "<<func2()<<endl;
    cout<<"after calling func2 i = "<<i<<endl;
    return 0;
}
