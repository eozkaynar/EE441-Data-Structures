#include <iostream>
#include "stack.hpp"

using namespace std;

void Deblank(char *s,char *t)
{
    while (*s != '\0')
    {
        if(*s != ' ')
        {
            *t = *s;
            t++;
        }
        s++;
    }
    *t = '\0'; // append NULL to new string
}
