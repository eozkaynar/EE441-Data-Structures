#include <iostream>

using namespace std;

class Point
{
    private:
        int p;
    public:
        Point ()
        {
            p=0;
            cout<<"Default Constructor is called\n";
        }
        Point(int pIn)
        {
            p = pIn;
            cout<<"User-Defined Constructor is called\n";
        }
        Point(const Point &t)
        {
            p = t.p;
            cout<<"Copy Constructor is called\n";
        }
        Point& operator= (const Point &t)
        {
            p = t.p;
            cout<<"Assignment Operator is called\n";
            return *this;
        }
};

int main()
{
    Point *t1, *t2;

    t1 = new Point(5);  // User defined constructor is called
    t2 = new Point(*t1); // Copy constructor is called

    Point t3 = *t1; //Copy constructor is called
    Point t4;       // Default constructor is called
    t4 = t3;        //Assignment Operator is called

    return 0;
}
