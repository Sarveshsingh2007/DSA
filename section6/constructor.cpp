#include<iostream>
#include "constructorclass.cpp"

using namespace std;

int main(){

    cout<<"Default Constructor Demo: "<<endl;
    cout<<endl;
    Student s1;
    s1.display();
    cout<<endl;
    Student s2;
    s2.display();

    cout<<endl;
    cout<<endl;

    cout<<"Parameterized Constructor Demo: "<<endl;
    Student s3(10);
    s3.display();
    cout<<endl;
    Student s4(10, 25);
    s4.display();
    cout<<endl;

    return 0;
}    