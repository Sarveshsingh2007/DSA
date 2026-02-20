#include<iostream>
using namespace std;

void count(int a[], int n, int x, int i, int &ans){
    if(i==n) return;

    if(a[i]==x){
        ans++;
    }
    count(a,n,x,i+1,ans);
}

int main(){
    int a[] = {6,5,5,6,6,5,5};
    int ans=0;
    count(a,7,5,0, ans);
    cout<<ans<<endl;
}