#include<bits/stdc++.h>
using namespace std;

void num(int n){
    // base case 
    if(n==0) return; // mandatory

    // recursive case 
    num(n-1); // 1,2,3,4,5.......n-1

    cout<<n<<endl;
    return; //optional

}

void num2(int n){
    // base case 
    if(n==0) return;

    cout<<n<<endl;
    // recursive case 
    num2(n-1); // 1,2,3,4,5.......n-1
    return;
}

int main(){
    num(5);
    num2(5);
    return 0;
}