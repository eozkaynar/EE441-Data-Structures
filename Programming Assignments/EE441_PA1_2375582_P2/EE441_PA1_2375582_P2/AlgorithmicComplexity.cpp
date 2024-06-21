#include <iostream>
#include "AlgorithmicComplexity.hpp"
using namespace std;


void print_backwards(char const *string)
{
    char temp;
    // Hold first item of string
    temp = *(string);

    // Termination (check for null-terminated string)
    if(temp == '\0')
        cout<< temp << endl;
    else
    {
        // call function for remaining string elements
        print_backwards(string+1);
        // print the current character
        cout<< temp << endl;
    }

}
int gcd(int n, int m)
{
    int temp;
    // Take the absolute value of the numbers if they are negative
    if(n<0)
        n = abs(n);
    if(m<0)
        m = abs(m);
    // Return zero if any number is zero
    if((n == 0)||(m == 0))
        return 0;

    while (m != 0) {
        temp = m;
        m = n % m;
        n = temp;
    }
    return n;

}
int lcm(int n, int m)
{
    // Take the absolute value of the numbers if they are negative
    if(n<0)
        n = abs(n);
    if(m<0)
        m = abs(m);
    // Return zero if any number is zero
    if((n == 0)||(m == 0))
        return 0;
    // If they are equal return any one of them
    if (n == m)
        return m;
    return (m*n)/gcd(n,m);
}

