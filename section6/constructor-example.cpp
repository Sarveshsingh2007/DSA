#include<iostream>
#include "constructor-example-class.cpp"
using namespace std;

int main(){
    Student s1;
    s1.display();

    Student s2(20);
    s2.display();

    Student s3(20, 1);
    s3.display();

    Student s4(s3);
    s4.display();

    Student s5;
    s5 = s2;
    s5.display();


    return 0;
}
