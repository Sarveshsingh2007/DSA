#include<iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);

    int suff[4];
 
    suff[n-1] = a[n-1];

    for(int i = n-2; i >= 0; i--){
        suff[i] = a[i] + suff[i+1];
    }

    for(int i = 0; i < n; i++){
        cout << suff[i] << " ";
    }

    return 0;
}