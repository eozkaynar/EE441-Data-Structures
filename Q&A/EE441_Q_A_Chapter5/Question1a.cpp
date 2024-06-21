# include <iostream>
#include <cstring>
using namespace std;

void AppendArray(char* &a, char* &b,int size_a, int size_b)
{
    char *c = new char[size_a+size_b];
    for (int i = 0; i < size_a; i++)
        *(c+i) = *(a+i);
    for (int i = size_a; i < size_a+size_b; i++)
        *(c+i) = *(b+i-size_a);

    delete []a;
    a = c;
    delete []b;
    b = c + size_a;

    for (int i = 0; i<size_a+size_b;i++)
        cout<<c[i]<<endl;

}
void InterleaveArrays(char* &a, char* &b,int n)
{
    char* c = new char[2*n];
    for (int i = 0; i < n; i++)
    {
        c[2*i]   = a[i];
        c[2*i+1] = b[i];
    }
    delete []a;
    a = c;
    delete []b;
    b = c + 2*n-1;
    cout<<c<<endl;
}
void AppendMirroredArrays(char* &a, char* &b,int n)
{
    char *c = new char[2*n];
    for (int i = 0; i < n; i ++)
    {
        c[i]        = a[i];
        c[2*n-1-i]  = a[i];
    }

    delete []a;
    a = c;
    b = c+2*n-1;

    cout<<c<<endl;

}

void SplitArrays(int* &a, int* &b, int n,int m)
{
    int *arr1 = new int[m];
    int *arr2 = new int[n-m];

    for (int i = 0; i < m; i++)
        arr1[i] = a[i];
    for (int i = 0; i < n-m; i++)
        arr2[i] = a[m+i];

    delete []a;
    a = arr1;
    b = arr2;
}
int main()
{
    const int n = 4;
    const int m = 2;
    int *a = new int[n];
    int *b = NULL;
    // Values are written in the arrays – not your task
    *a = 1;
    *(a+1) = 2;
    *(a+2) = 3;
    *(a+3) = 4;

    SplitArrays(a, b, n, m);
    for(int i = 0; i < m; i++)
        cout << *(a+i) << " ";
    cout << endl;
    for(int i = 0; i < n - m; i++)
        cout << *(b+i) << " ";
    cout << endl;

    return 0;
}
