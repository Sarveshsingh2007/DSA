#include<bits/stdc++.h>
using namespace std;

int miniSteps(int n){
    if(n<=1) return 0;
    int x = miniSteps(n-1);
    int y,z;
    y = z = INT_MAX;
    if(n%2==0) {
        y = miniSteps(n/2);
    }

    if(n%3==0){ 
        z = miniSteps(n/3);
    }
    int ans = 1+ min(x, min(y,z));
    return ans;
}

int main(){
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Minimum Steps: "<<miniSteps(n);
    return 0;
}