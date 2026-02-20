#include<iostream>
using namespace std;

void printAllIndex(int a[], int n, int x, int i){
    if(i == n){
        return;
    }

    if(a[i] == x){
        cout << i << " ";
    }

    printAllIndex(a, n, x, i + 1);
}

int main(){
    int a[] = {2,3,2,3,3,4};
    printAllIndex(a, 6, 3, 0);  
    return 0;
}
