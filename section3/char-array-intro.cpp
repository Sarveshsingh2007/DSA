#include<iostream>
using namespace std;
int main(){

    char name[100];
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Your name is "<<name<<endl;
    cout<<"size of array is: "<<sizeof(name)<<endl;
    cout<<name[7]<<endl;
    name[7] = 'x';
    cout<<name<<endl;

    return 0;
}