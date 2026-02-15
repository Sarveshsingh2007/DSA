#include<iostream>
using namespace std;

int countzero(int n){
    // base case
    if(n==0) return 0;

    //recusive case
    int a = countzero(n/10);

    // calculation
    int last_digit = n%10;
    if(last_digit == 0){
        return 1+a;
    }else{
        return a;
    }

}

int main(){
    cout<<countzero(230140301);
    return 0;
}