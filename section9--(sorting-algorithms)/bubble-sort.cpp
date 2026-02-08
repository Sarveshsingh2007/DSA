#include<iostream>
using namespace std;

void bubbleSort(int a[], int n){
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cout<<"enter number of elements: ";
    cin>>n;

    int a[n];
    cout<<"Enter "<<n<<" elements \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Array :";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
    bubbleSort(a, n);
    cout<<"Bubble Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}

/*  
STEPS:-
1. Start from the first element of the array.
2. Compare the first element with the next element. (i with i+1)
3. If i is greater than i+1, swap the values.
4. Move to the next pair of adjacent elemensts and repeat the comparison and swapping.
5. Continue this process until the end of the array — after one full pass, the largest element moves to the last position.
6. Repeat the same process for the remaining unsorted part of the array.
7. Stop when all passes are completed (n-1 passes) or when no swaps occur (array already sorted).
*/