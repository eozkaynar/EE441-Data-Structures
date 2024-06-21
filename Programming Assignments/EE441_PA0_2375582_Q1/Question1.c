#include <stdio.h>
#include "Question1.h"
void sortArray(float *p,int size)
{
    float temp;
    for (int i = 0; i < size; i++)
{
       for (int j = 0; j < size-1; j++)

            {
                if (*(p+j) > *(p+j+1))
                {
                    temp = *(p+j+1);
                    *(p+j+1) = *(p+j);
                    *(p+j)   =  temp;
                }
            }
}

}

void printArray(float *p, int size)
{
    for (int i = 0; i<size;i++)
    {
        printf("%f",*(p+i));
        printf(" ");
    }
}
