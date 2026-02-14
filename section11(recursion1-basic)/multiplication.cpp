#include<bits/stdc++.h>
using namespace std;

int mul(int m, int n){ 
    // m*n without using * operator
    //base case
    if(n==0) return 0;

    //recursive case
    int a = mul(m, n-1); // m*(n-1)
    
    return a + m;
}


int main(){
    cout<<mul(3,5);
}