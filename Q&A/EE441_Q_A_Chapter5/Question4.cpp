#include <iostream>
using namespace std;

template<class T>

class X
{
    public:
        int n;
        T   *p;

        X (const int nn,const T &item);

        // Copy constructor
        X (const X<T> &xx);
        ~X(void);
        X<T> &operator= (const X<T> &r);
};

template <class T>
X<T>:: X(const int nn, const T &item)
{
    n = nn;
    if(n)
    {
        p = new T[n];
        for (int i = 0; i<n; i++)
            p[i] = item;
    }
}
template <class T>
X<T>:: X(const X<T> &xx)
{
    n = xx.n;
    if(n)
    {
        p = new T[n];
        for (int i = 0; i<n; i++)
            p[i] = xx.p[i];
    }
}

template <class T>
X<T>:: ~X(void)
{
    if(n)
        delete []p;
}

template <class T>
X<T> &X<T> ::operator=(const X<T> &r)
{

    if(n)
        delete []p;
    n = r.n;
    if(n)
    {
        p = new T[n];
        for (int i = 0; i<n; i++)
            p[i] = r.p[i];
    }
    return *this;
}

int main()
{
    int nn = 3;
    int item = 5;
    X<int> * aa = new X<int>(nn,item);
    cout << aa->n << endl;
    for(int ii=0; ii<aa->n; ii++)
        cout << aa->p[ii] << " ";
    return 0;
}
