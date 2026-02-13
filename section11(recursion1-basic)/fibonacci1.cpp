#include<bits/stdc++.h>
using namespace std;

fib(int n){
    // base case
    if(n==0) return 0;
    if(n==1) return 1;

    // recursive code
    int a = fib(n-1);
    int b = fib(n-2);

    // calculation
    return a + b;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}