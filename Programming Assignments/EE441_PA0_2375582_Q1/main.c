#include <stdio.h>

int main()
{
    const int arrSize;
    float arr[20];

    printf("Array Size: ");
    scanf("%d", &arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        printf("arr[%d]: ",i);
        scanf("%f",&arr[i]);
    }

    sortArray(arr,arrSize);
    printArray(arr,arrSize);
    return 0;
}
