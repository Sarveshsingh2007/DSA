#include<iostream>
using namespace std;

class Student{
    int age;
    public:
        // default constructor
        Student(){
            cout<<"Default Constructor Called"<<endl;
        }
        // parameterized constructor
        Student(int a){
            age = a; // we can not write age = age // we have to use this keyword-> holds the address of current object.
        }
        Student(int a, int r){
            age=a;
            roll_no=r;
        }
        int roll_no;
        void display(){
            cout<<"age is: "<<age<<endl;
            cout<<"roll no is: "<<roll_no<<endl;
        }
};