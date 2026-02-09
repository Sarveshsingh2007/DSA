#include<iostream>
using namespace std;

void bubbleSort(int a[], int n){
    for(int i=0;i<=n-1;i++){
        int flag = 0;
        for(int j=0;j<n-1;j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]) flag = 1;
            }
        }
        if (flag == 0){ // already sorted
            break; // come out of the loop
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