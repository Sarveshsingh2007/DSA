#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];
    cout<<"Size of an array is: "<<sizeof(arr)<<endl;
    cout<<"Enter elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"Original: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Reverse: ";
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }

    return 0;
}