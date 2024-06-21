#include <iostream>
#include <chrono>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

using namespace std::chrono;

int saveF[100];

int Fibonacci (int n){
    int sum;
    int prev=-1;
    int result=1;
    for(int i=0;i<=n;i++){
        sum=result+prev;
        prev=result;
        result=sum;
    }
    return result;
}


int FibonacciR (int n){
    if(n==0||n==1)
        return n;
    else
        return FibonacciR(n-1)+FibonacciR(n-2);
}

int FibonacciRwithM(int n) {
    if(n==0||n==1)
        return n;
    if (saveF[n] > 0)
        return saveF[n];
    // Recursion
    saveF[n] = FibonacciRwithM(n-1) + FibonacciRwithM(n-2);
    return saveF[n];
}

int binomCoeffRecursive(int N, int k){
    if(k==0||N==k)
        return 1;
    return binomCoeffRecursive(N-1,k)+ binomCoeffRecursive(N-1, k-1);
}

double binomCoeffIterative(int N, int k){
    if(k==0||N==k)
        return 1;
    double result=1;
    int t=min(k,N-k);
    for(int i=0;i<t;i++)
    {
           result *= (double)(N-i)/(i+1);
    }
    return result;
}

int main(){

    cout << "========================" << endl;
    cout << "===== Fibonnacci =======" << endl;
    cout << "========================" << endl;
    int f = 30;
    auto start = high_resolution_clock::now();
    int fb=Fibonacci(f);
    auto stop = high_resolution_clock::now();
    auto durationIt = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    int fbR=FibonacciR(f);
    stop = high_resolution_clock::now();
    auto durationRec = duration_cast<microseconds>(stop - start);

    start = high_resolution_clock::now();
    int fbRwithM=FibonacciRwithM(f);
    stop = high_resolution_clock::now();
    auto durationRecWithM = duration_cast<microseconds>(stop - start);

    cout<< "Fibonacci results: iterative:"<<fb<<", recursive:"<<fbR<<", recursive with memory:"<<fbRwithM<<"\n";
    cout << "Time iterative: " << durationIt.count() << " Time recursive: " << durationRec.count() << " Time recursive with memory: " << durationRecWithM.count()<< endl;

    cout << "========================" << endl;
    cout << "===== Binomial =======" << endl;
    cout << "========================" << endl;

    start = high_resolution_clock::now();
    int binomialRecursive=binomCoeffRecursive(15,2);
    stop = high_resolution_clock::now();
    auto durationRecBinom = duration_cast<microseconds>(stop - start);
    start = high_resolution_clock::now();
    double binomialIterative=binomCoeffIterative(15,2);
    stop = high_resolution_clock::now();
    auto durationItBinom = duration_cast<microseconds>(stop - start);
    cout<< "Binomial results: iterative:"<<binomialIterative<<", recursive:"<<binomialRecursive<<"\n";
    cout << "Time iterative: " << durationItBinom.count() << " Time recursive: " << durationRecBinom.count() << endl;

    return 0;

}

