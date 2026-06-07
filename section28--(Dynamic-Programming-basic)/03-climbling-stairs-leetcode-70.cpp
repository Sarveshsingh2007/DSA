#include<bits/stdc++.h>
using namespace std;

int ClimbStairs(int n){
    int *dp = new int[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int output = dp[n];
    delete []dp;
    return output;
}

int main(){
    int n;
    cin>>n;
    cout<<ClimbStairs(n);
    return 0;
}