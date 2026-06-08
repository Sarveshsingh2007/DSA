#include<iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1) return n;

    return fib(n-1) + fib(n-2);
}

int fib2(int n, int arr[]){
    if(n == 0 || n == 1) return n;

    if(arr[n] != 0) return arr[n];

    int output = fib2(n-1, arr) + fib2(n-2, arr);

    arr[n] = output;

    return output;
}

int fib3(int n){

    if(n == 0) return 0;
    if(n == 1) return 1;

    int *arr = new int[n+1];

    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    int output = arr[n];

    delete[] arr;

    return output;
}

int main(){

    int n;

    cout << "Enter value of n: ";
    cin >> n;

    int *arr = new int[n+1];

    for(int i = 0; i <= n; i++){
        arr[i] = 0;
    }

    cout << "Fib of n using DP (Bottom-Up): "
         << fib3(n) << endl;

    cout << "Fib of n using Memoization: "
         << fib2(n, arr) << endl;

    cout << "Fib of n using Recursion: "
         << fib(n) << endl;

    delete[] arr;

    return 0;
}