#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    //base case
    if(n==0) return 0;
    if(n==1) return 1;

    // recursive case
    int a = sum(n/10);

    int last_digit = n%10;
    return a + last_digit;

}

int main(){
    int n;
    cin>>n;
    cout<<sum(n);
}