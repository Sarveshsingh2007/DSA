#include<iostream>
#include<algorithm>
using namespace std;

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
    
    sort(a, a+n);

    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}