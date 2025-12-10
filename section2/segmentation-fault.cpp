#include<iostream>
using namespace std;
int main(){
        
    // Segmentation fault is also known as runtime error which means
    // we are trying to access the memory which is not ours or not created.

    // int a[10];
    // cout<<a[200];
    int a[10000000];

    return 0;
}