#include <iostream>

using namespace std;

#define SELECT 1

class MyClass{
    private:
        char *c;
    public:
        #if SELECT == 1
            MyClass(const int& n);
        #else
            MyClass(void);
        #endif
        char& Put(const int &n);
        char& Get(const int &n);
        #if SELECT == 1
            ~MyClass(void);
        #endif
 };

#if SELECT == 1
    MyClass::MyClass(const int& n){
        c = new char[n];
    };
#else
    MyClass::MyClass(void){
};
#endif // SELECT


char& MyClass::Put(const int& n){
    return c[n];
};

char& MyClass::Get(const int& n){
    return c[n];
};

#if SELECT == 1
    MyClass::~MyClass(void){
        delete c;
    }
#endif

void MyFn(MyClass& m1){
    MyClass *mc;
    #if SELECT == 1
        mc = new MyClass(10);
    #else
        mc = new MyClass;
    #endif
    mc->Put(3) = 'a';
    m1.Put(3) = mc->Get(3);
};

int main()
{
    int n;
    #if SELECT == 1
        MyClass m1(20);
    #else
        MyClass m1;
    #endif
    cin >> n;
    MyFn(m1);
    cout << m1.Get(3);

    return 0;
};
