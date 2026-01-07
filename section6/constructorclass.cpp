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
            age = a;
        }
        int roll_no;
        void display(){
            cout<<"age is: "<<age<<endl;
            cout<<"roll no is: "<<roll_no<<endl;
        }
};