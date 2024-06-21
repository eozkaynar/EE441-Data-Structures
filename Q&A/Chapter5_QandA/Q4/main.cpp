#include "X.hpp"

#include <iostream>
using namespace std;

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
