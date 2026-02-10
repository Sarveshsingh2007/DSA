#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n < 0) return -1;     // invalid
    if(n == 0 || n == 1) return 1;   // base case

    int smallAns = fact(n-1);
    return n * smallAns;
}

int main(){
    int n;
    cout<<"enter the value of n: ";
    cin>>n;

    int ans = fact(n);

    if(ans == -1)
        cout<<"Factorial not defined for negative numbers";
    else
        cout<<"factorial of "<<n<<" is: "<<ans<<endl;
}
