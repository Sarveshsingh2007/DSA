#include<iostream>
using namespace std;

int firstIndex(int a[], int n, int x, int i){
    //base case
    if(i==n) return -1;
    if(a[i] == x){
        return i;
    }
    return firstIndex(a,n,x,i+1);

}


int main(){
    int a[] = {2,3,4,3,4,3,4};
    int n = 7;
    int x = 4;
    cout<<firstIndex(a, n, x, 0);
    return 0;
}