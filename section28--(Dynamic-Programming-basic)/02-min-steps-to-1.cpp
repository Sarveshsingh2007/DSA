#include<bits/stdc++.h>
using namespace std;

int minSteps(int n){
    if(n<=1) return 0;
    int x = minSteps(n-1);
    int y,z;
    y = z = INT_MAX;
    if(n%2==0) {
        y = minSteps(n/2);
    }

    if(n%3==0){ 
        z = minSteps(n/3);
    }
    int ans = 1+ min(x, min(y,z));
    return ans;
}

int helper(int n, int *ans){
    // base case 
    if(n<=1) return 0;
    if(ans[n]!=-1) return ans[n];
    int x = helper(n-1, ans);
    int y,z;
    y=z=INT_MAX;
    if(n%2==0){
        y=helper(n/2, ans);
    }
    if(n%3==0){
        z=helper(n/3, ans);
    }
    int output = 1+min(x,min(y,z));
    // save ans
    ans[n] = output;
    return output;


}

int minSteps2(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return helper(n,ans);
}

int minSteps3(int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 0;
    
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        if(i%2==0){
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        if(i%3==0){
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }
    int ans = dp[n];
    delete []dp;
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Minimum Steps Brute Force: "<<minSteps(n)<<endl;
    cout<<"Minimum Steps Memoization: "<<minSteps2(n)<<endl;
    cout<<"Minimum Steps bottom up method: "<<minSteps3(n)<<endl;
    return 0;
}