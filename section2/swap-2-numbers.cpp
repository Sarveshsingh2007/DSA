#include<iostream>
using namespace std;
int main(){
    int a, b;
    int temp;
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;
    
    cout<<"Value of a before swapping: "<<a<<endl;
    cout<<"Value of b before swapping: "<<b<<endl;

    // temp = a;
    // a = b;
    // b = temp;
    
    swap(a,b);

    cout<<"Value of a after swapping: "<<a<<endl;
    cout<<"Value of b after swapping: "<<b<<endl;

    return 0;
}