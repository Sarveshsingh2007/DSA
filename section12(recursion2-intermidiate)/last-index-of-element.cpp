#include<iostream>
using namespace std;

int lastIndex(int a[], int n, int x, int i){
    if(i==-1) return -1;
    if(a[i] == x){
        return i;
    }
    return lastIndex(a,n,x,i-1);

}
int lastIndex2(int a[], int n, int x){
    if(n==0) return -1;
    if(a[n-1] == x){
        return n-1;
    }
    return lastIndex2(a,n-1,x);

}

int lastIndex3(int a[], int n, int x, int i){
    if(i==n) return -1;
    int indexInRem =  lastIndex3(a, n, x, i+1);
    if(indexInRem == -1){
        if(a[i] == x){
            return i;
        }else{
            return -1;
        }
    }
    
}

int main(){
    int a[] = {2,3,4,3,4,3,4};
    int n = 7;
    int x = 3;
    cout<<lastIndex3(a, n-1, x);
    return 0;
}