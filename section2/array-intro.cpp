#include<iostream>
using namespace std;
int main(){
    int a[5] = {2,3,4,5,7};  // initialization
    cout<<"value at index 2 is "<<a[2]<<endl;    // printing values

    int arr[10] = {1,2,3,4};
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int ar[10];
    for(int i=0;i<10;i++){
        cout<<ar[i]<<" "; // prints garbage values
    }
    cout<<endl;

    int b[10];
    for(int i=1;i<10;i++){
        b[i]= i+i;  // given values to all the index in the array
        cout<<b[i]<<" ";
    }
    cout<<endl;

    // int a[]; wrong way 

    int c;
    cout<<sizeof(c)<<endl;

    int d[10] = {1,2,3};
    cout<<sizeof(d);

    return 0;
}   