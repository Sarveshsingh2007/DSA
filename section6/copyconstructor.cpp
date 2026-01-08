#include<iostream>
#include "copyconstructorclass.cpp"

using namespace std;
int main(){
    Employee e1(12,23);// parameterized constructor
    e1.display();
    cout<<endl;

    Employee e2(e1);// copy constructor
    e2.display();
    return 0;
}