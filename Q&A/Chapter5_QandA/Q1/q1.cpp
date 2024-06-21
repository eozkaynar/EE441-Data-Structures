#include <iostream>

using namespace std;

#define SELECT 4
// 1: AppendArray main active
// 2: InterleaveArrays main active
// 3: AppendMirroredArrays main active
// 4: SplitArrays main active

void AppendArray(char *&a, char *&b, int size_a, int size_b)
{
    char *c = new char[size_a + size_b];
    for(int i = 0; i < size_a;i++)
        *(c+i) = *(a+i);
    for(int i = 0; i < size_b;i++)
        *(c+i+size_a) = *(b+i);
    delete [] a;
    a = c;
    delete [] b;
    b = c+size_a;
}

void InterleaveArrays(char *&a, char *&b, int n)
{
    char *c = new char[2*n];
    for(int i = 0; i < n;i++)
    {
        *(c+2*i) = *(a+i);
        *(c+2*i+1) = *(b+i);
    }
    delete [] a;
    a = c;
    delete [] b;
    b = c+2*n-1;
}

void AppendMirroredArrays (char *&a, char *&b, int n)
{
    char *c = new char[2*n];
    for(int i = 0; i < n;i++)
    {
        *(c+i) = *(a+i);
        *(c+2*n-i-1) = *(a+i);
    }
    delete [] a;
    a = c;
    b = c+2*n-1;
}

void SplitArrays(char *&a, char *&b, int n, int m)
{
    char *c = new char[m];
    b = new char[n - m];
    for(int i = 0; i < m; i++)
        *(c+i) = *(a+i);
    for(int i = 0; i < n-m; i++)
        *(b+i) = *(a+m+i);
    delete [] a;
    a = c;
}

#if SELECT == 1
// This is the main function, you need NOT modify.
int main()
{
    const int size_a = 3;
    const int size_b = 4;
    char *a = new char[size_a];
    char *b = new char[size_b];
    // Values are written in the arrays – not your task
    *a = 'a';
    *(a+1) = 'b';
    *(a+2) = 'c';
    *b = 'z';
    *(b+1) = 'y';
    *(b+2) = 'x';
    *(b+3) = 'u';
    AppendArray(a, b, size_a, size_b);
    for(int i = 0; i < size_a + size_b; i++)
        cout << *(a+i) << " ";
    cout << endl;
    cout << "b: " << *b << endl;
    return 0;
}

#elif SELECT == 2
// This is the main function, you need NOT modify.
int main()
{
    const int n = 4;
    char *a = new char[n];
    char *b = new char[n];
    // Values are written in the arrays – not your task
    *a = 'a';
    *(a+1) = 'b';
    *(a+2) = 'c';
    *(a+3) = 'd';
    *b = 'z';
    *(b+1) = 'y';
    *(b+2) = 'x';
    *(b+3) = 'u';
    InterleaveArrays(a, b, n);
    for(int i = 0; i < 2*n; i++)
        cout << *(a+i) << " ";
    cout << endl;
    cout << "b: " << *b << endl;
    return 0;
}

#elif SELECT == 3
// This is the main function, you need NOT modify.
int main()
{
    const int n = 4;
    char *a = new char[n];
    char *b = NULL;
    // Values are written in the arrays – not your task
    *a = 'a';
    *(a+1) = 'b';
    *(a+2) = 'c';
    *(a+3) = 'd';
    AppendMirroredArrays (a, b, n);
    for(int i = 0; i < 2*n; i++)
        cout << *(a+i) << " ";
    cout << endl;
    cout << "b: " << *b << endl;
    return 0;
}

#elif SELECT == 4
// This is the main function, you need NOT modify.
int main()
{
    const int n = 4;
    const int m = 2;
    char *a = new char[n];
    char *b = NULL;
    // Values are written in the arrays – not your task
    *a = 'a';
    *(a+1) = 'b';
    *(a+2) = 'c';
    *(a+3) = 'd';

    SplitArrays(a, b, n, m);
    for(int i = 0; i < m; i++)
        cout << *(a+i) << " ";
    cout << endl;
    for(int i = 0; i < n - m; i++)
        cout << *(b+i) << " ";
    cout << endl;
    return 0;
}

#endif // SELECT
