#include<iostream>
#include<vector>
using namespace std;

void saveAllPos(int a[], int n, int x, int i, vector<int> &ans){
    if(i==n) return;
    if(a[i] == x){
        ans.push_back(i);
    }
    saveAllPos(a,n, x,i+1, ans);
}

int main(){
    int a[] = {5,5,6,5,6,7};
    vector<int> v;
    saveAllPos(a, 6, 5, 0, v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}