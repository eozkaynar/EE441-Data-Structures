#include <iostream>
using namespace std;

int BinarySearch(int list[], int low, int high, int key)
{
    int mid;
    int midvalue;

    while(low<=high){
        mid  = (low+high)/2;
        midvalue = list[mid];
        if(key == midvalue)
            return mid;
        else if (key < midvalue)
            high = mid - 1;
        else
            low = mid+1;
    }
    return -1;
}
int Factorial(int n)
{
    if(n == 0)
        return 1;
    return n*Factorial(n-1);
}

int RecursiveBinarySearch(int A[], int low, int high, int key)
{
    int mid;
    int midval;
    if (low>high)
        return -1;
    else
    {
        mid = (low+high)/2;
        midval = A[mid];
        if(key == midval)
            return mid;
        else if (key < midval)
            return RecursiveBinarySearch(A,low,mid-1,key);
        else
            return RecursiveBinarySearch(A,mid+1,high,key);
    }
}
int main()
{
    int liste[] = {5,17,36,37,45};
    cout << BinarySearch(liste,0,4,36) << endl;
    cout << RecursiveBinarySearch(liste,0,4,36) << endl;
    return 0;
}
