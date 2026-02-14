#include<iostream>
using namespace std;

int count(int n){
    //base case
    if(n==0) return 0;

    // recursive case
    int a = count(n/10);

    return a+1;
}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
}