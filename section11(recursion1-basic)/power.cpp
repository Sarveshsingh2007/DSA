#include<bits/stdc++.h>
using namespace std;

int pow(int x, int n){
    //base case
    if(n==0) return 1;
    
    //recursion
    int a = pow(x,n-1);

    //calculation
    return x*a;
}

int main(){
    cout<<pow(5,3);
    return 0;
}