#include <iostream>
using namespace std;

class SA
{
    public:

        int *s, a;

        SA(int &o, int aa)
        {
            s=&o;
            a=aa;
        }

        void A(int &n)
        {
            *s=*s**s;
            n=a*n;
            sa();
        }

        void B(int *n)
        {
            *s=*s**s;
            *n=a**n;
            sa();
        }

        void C(int  n)
        {
            *s=*s**s;
            n=a*n;
            sa();
        }

        void D(int *n)
        {
            s=&a;
            *n=a**n;
            sa();
        }

        void sa()
        {
            cout <<"SA:"<<*s<<":"<<a<<endl;
        }
};

int main(void)
{
        int i=1, j=2, k=3;
        SA x(i,j);
        x.sa();
        x.A(k);
        x.A(x.a);
        x.B(x.s);
        cout<<k<<endl;
        x.C(k);
        x.D(&x.a);
        x.D(x.s);
        return 0;
}
