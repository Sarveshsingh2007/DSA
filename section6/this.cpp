#include<iostream>
#include "thisclass.cpp"
using namespace std;
int main(){

    User u1(1,21);
    u1.display();
    cout<<endl;
    User u2(2, 20);
    u2.display();

    return 0;
}