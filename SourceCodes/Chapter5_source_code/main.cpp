#include <iostream>
using namespace std;

#include "DynamicClass.hpp"

void mdemo(int initval1, float initval2)
{
    int *p1=new int;
    float *p2=new float[3];
    *p1=initval1;
    int i;
    for(i=0;i<3;i++)
        p2[i]=initval2*2;
    cout<<*p1<<" ";
    for(i=0;i<3;i++)
        cout<<p2[i]<<" ";
    cout<<endl;
    delete p1;
    delete []p2;

    p1=new int[3];
    p2=new float;
    *p2=initval2;
    for(i=0;i<3;i++)
        *(p1+i)=initval1;
    cout<<*p2<<" ";
    for(i=0;i<3;i++)
        cout<<*(p1+i)<<" ";
    cout<<endl;
    delete []p1;
    delete p2;
}

void mdemo2(int initval1, float initval2)
{
    int size=3;
    cout<<size<<endl;
    int *p1=new int;
    float *p2= new float[size];
    *p1=initval1;
    int i;
    for(i=0;i<3;i++)
        p2[i]=initval2*2;
    cout<<*p1<<" ";
    for(i=0;i<size;i++)
        cout<<p2[i]<<" ";
    cout<<endl;
    delete p1;
    delete []p2;
}

void DestroyDemo(int m1,int m2)
{
    DynamicClass<int> Obj(m1,m2);
}

template <class T>
DynamicClass<int> Demo(DynamicClass<T> one, DynamicClass<T>& two, T m)
{
    DynamicClass<T> obj(m,m);
    return obj;
}

int main () {
    mdemo(4, 2.5);

    int init1=4;
    float init2=2.5;
    int *z1;
    float *z2;
    mdemo2(init1, init2);
    z1=new int (init1*2);
    z2=new float(init2+1.5);
    mdemo2(*z1,*z2);
    delete z1;
    delete z2;

    //Dynamic Class object
    DynamicClass<int> StaticObj(1,100);

    //pointer variable
    DynamicClass<int>*DynamicObj;
    //allocate an object
    DynamicObj=new DynamicClass<int>(2,200);

    DestroyDemo(3,300);
    delete DynamicObj;

    DynamicClass<int> Obj5(5,500);
    DynamicClass<int> *ptr=Obj5.Address();
    //same as:
    //DynamicClass<int> *ptr=&Obj5;
    ptr->GetMembers();
    DynamicClass<int>* ptr6=new DynamicClass<int> (6,600);
    ptr6->GetMembers();

    DynamicClass<int> A(3,5), B=A, C(0,0);
    C=Demo(A,B,5);

    return 0;
}

