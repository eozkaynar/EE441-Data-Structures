#include <iostream>

using namespace std;

int F(int *x, int *&y,int&z)
{
	int *w=y;
	y=&z;
    *y=*(x+1);
    x[2]=(*w)*z;
    x=x+2;
    return *x;
}

int main(void)
{
	int a=20, b=100, f;
	int A[3];
    int *c=&b;
    int *d=A+1;
	for (int i=0; i<3; i++)
		A[i]=3*(i+1);
    //control point 1
    cout<<"a:"<<a <<" b:"<<b<<"\n";
    cout<<"*c:"<<*c<<" *d:"<<*d <<" *A:"<<*A<<"\n";
    cout<<"A[0]:"<<A[0]<< " A[1]:"<<A[1]<< " A[2]:"<<A[2]<<"\n\n";

	f=F(A,c,a);
//control point 2
    cout<<"a:"<<a <<" b:"<<b<<"\n";
    cout<<"*c:"<<*c<<" *d:"<<*d <<" *A:"<<*A<<"\n";
    cout<<"A[0]:"<<A[0]<< " A[1]:"<<A[1]<< " A[2]:"<<A[2]<<"\n";
    cout<<"f:"<<f<<"\n";
    return 0;
}

