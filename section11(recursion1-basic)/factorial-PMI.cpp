#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    // base class step 1 of PMI
    if(n==0) return 1;
    int smallAns = fact(n-1); // 2nd step Assumption
    int ans = n * smallAns; // 3rd step Calculation
    return ans;
}

int main(){
    cout<<fact(4)<<endl;
    return 0;
}