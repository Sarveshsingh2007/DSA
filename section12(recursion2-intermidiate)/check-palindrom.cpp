#include<iostream>
using namespace std;

bool checkPalindrom(int a[], int n){
    int s=0;
    int e= n-1;

    while(s<e){
        if(a[s] != a[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main(){
    int a[] = {1,2,3,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    if(checkPalindrom(a, n)){
        cout<<"Array is palindrom";
    }else{
        cout<<"Array is not plaindrom";
    }

    return 0;
}