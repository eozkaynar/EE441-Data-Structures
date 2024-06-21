#include <iostream>
using namespace std;

class Point
{
    private:
        int p;
    public:
        Point()
        {
            p=0;
            cout<<"Default Constructor is called\n";
        }

        Point(int pIn)
        {
            p=pIn;
            cout<<"User-Defined Constructor is called\n";
        }

        Point(const Point &t)
        {
            p=t.p;
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
    t1 = new Point(5);
    t2 = new Point(*t1);
    Point t3 = *t1;
    Point t4;
    t4 = t3;

    return 0;
}
