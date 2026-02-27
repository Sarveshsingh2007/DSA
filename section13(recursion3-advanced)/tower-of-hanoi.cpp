#include<iostream>
using namespace std;

int toh(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    return toh(n-1) + 1 + toh(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<toh(n)<<endl;
    return 0;
}