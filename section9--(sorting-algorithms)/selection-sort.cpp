#include<iostream>
#include<climits>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int smallest = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];  

    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    selectionSort(arr, n);
    cout<<"Selection Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


/*
STEPS:-
1. Start from the first element of the array.
2. Assume the current position i contains the smallest element.
3. Compare the smallest with all the remaining elements from j=i+1 to n-1.
4. Find the smallest index from the remaining array.
5. Swap the smallest element with the element at the position i.
6. Move i to the next position and repeat until the array is sorted.
*/