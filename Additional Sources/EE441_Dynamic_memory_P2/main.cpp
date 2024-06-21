#include <iostream>

using namespace std;

#define SELECT 1

class Z
{
    private:
        int *z1; int *z2;
    public:
        Z(const int x1 = 0, const int x2 = 0);
        Z(const Z &X);
        int *first (void) const {return z1;};
        int *second (void) const {return z2;};
        ~Z(void);
};

Z::Z(const int x1,const int x2){
    z1 = new int(x1);
    z2 = new int(x2);
}

#if SELECT == 1
Z::Z(const Z &X){
    z1 = new int(*X.first() );
    z2 = new int(*X.second() );
}
#else
Z::Z(const Z &X){
    z1 = X.first();
    z2 = X.second();
}
#endif

Z::~Z(){
    delete z1;
    delete z2;
}

int main()
{
    Z firstZ;
    cout << "Content of firstZ: " << *firstZ.first() << " and " << *firstZ.second() << endl;
    Z secondZ(4,7);
    cout << "Content of secondZ: " << *secondZ.first() << " and " << *secondZ.second() << endl;
    Z thirdZ(secondZ);
    cout << "Content of thirdZ: " << *thirdZ.first() << " and " << *thirdZ.second() << endl;

    Z *zp;
    zp = new Z(3,5);
    Z a(6, *(zp->first() ) ), b=a, c(0,0);
    c = *zp;
    cout << "Content of c: " << *c.first() << " and " << *c.second() << endl;
    delete zp;
    cout << "Content of c: " << *c.first() << " and " << *c.second() << endl;

    cout << "Content of b: " << *b.first() << " and " << *b.second() << endl;
    *a.first() = 10;
    cout << "Content of b: " << *b.first() << " and " << *b.second() << endl;
    return 0;
}
