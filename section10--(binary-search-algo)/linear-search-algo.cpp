#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter total no of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int key;
    cout<<"Enter key to find in array: ";
    cin>>key;
    int pos = linearSearch(arr, n, key);
    if(pos == -1){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"Key found at index "<<pos<<endl;
    }

    return 0;
}