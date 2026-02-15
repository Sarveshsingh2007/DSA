#include<bits/stdc++.h>
using namespace std;

double gsum(int k){
    // base case
    if(k==0) return 1;

    // recursive case 
    double a = gsum(k-1);

    //calculatoin

    return a + 1.0/pow(2,k);
}

int main(){
    cout<<gsum(3);
    return 0;

}