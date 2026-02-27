#include<iostream>
using namespace std;
int main(){
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);
    int pref[4];
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    for(int i = 0; i < n; i++) {
        cout << pref[i] << " ";
    }
    return 0;
}