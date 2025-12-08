#include<iostream>
#include<climits>
using namespace std;
int main(){
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int a[n];
    cout<<"size of arrays is: "<<sizeof(a)<<endl; // size of a
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // printing the elements of array
    cout<<"Elements of array are: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    int largest = INT_MIN;
    int smallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]> largest){
            largest = a[i];
        }
        if(a[i]< smallest){
            smallest = a[i];
        }
    }
    
    cout<<"Largest number in the array is: "<<largest<<endl;
    cout<<"Smallest number in the array is: "<<smallest;

    return 0;
}