#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int a[n];
    cout<<"Enter elements: ";
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;

    cout<<"Original Array: ";
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    int s = 0;
    int e = n-1;

    while (s<=e){
        swap(a[s], a[e]);
        s++;
        e--;
    }

    cout<<"Reversed Array: ";
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    return 0;
}