#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int s = 0;
    int e = n - 1;

    while(s <= e){
        int mid = s + (e - s)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the total no of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);  // binary search requires sorted array

    cout<<"Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int key;
    cout<<"Enter key to find in array: ";
    cin>>key;

    int pos = binarySearch(arr, n, key);

    if(pos == -1){
        cout<<"Key not found"<<endl;
    }
    else{
        cout<<"Key found at index "<<pos<<endl;
    }

    return 0;
}
