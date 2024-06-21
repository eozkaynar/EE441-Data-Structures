#include <iostream>

#define debug 1

using namespace std;

void fun (int*&k, int *&z)
{
#if debug == 1
    int *a = k;
#endif
    //check1
#if debug == 1
    for(unsigned int i = 0; i < 5; i++)
        cout << *(a+i) << " ";
    cout << endl;
    cout << *k << endl;
    cout << endl;
#endif
    k=k+*z;
    // check2
#if debug == 1
    for(unsigned int i = 0; i < 5; i++)
        cout << *(a+i) << " ";
    cout << endl;
    cout << *k << endl;
    cout << endl;
#endif
    *(k+1)=*z+2;
    // check3
#if debug == 1
    for(unsigned int i = 0; i < 5; i++)
        cout << *(a+i) << " ";
    cout << endl;
    cout << *k << endl;
    cout << endl;
#endif
    *k=*(z+1);
    //check4
#if debug == 1
    for(unsigned int i = 0; i < 5; i++)
        cout << *(a+i) << " ";
    cout << endl;
    cout << *k << endl;
    cout << endl;
#endif
    k=z;
cout<<"out1: "<<*k<<"\n";
}


int main ()
{
    int A[5]={0,-1,-2,-3,-4};
    int B[3]={1,2,3};
    int* s=A;
    int*t=B;
    fun(s,t);
    cout<<"out2: "<<*s<<"\n";

   return 0;
}

