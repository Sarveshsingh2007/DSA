#include<iostream>
using namespace std;
class Student{
    int age;
public:
    ~Student(){ // destructor
        cout<<"------Destructor called-----"<<endl;
        cout<<endl;
    }
    // default
    Student(){
        cout<<"------Default Constructor called------"<<endl;
        cout<<endl;
    }
    // parmeterized
    Student(int roll_number){
        cout<<"------Parameterized Constructor called------"<<endl;
        this->roll_number = roll_number; // used this keyword for same parameter name
        cout<<endl;
    }
    Student(int a, int r){
        cout<<"------Constructor called-----"<<endl;
        age = a;
        roll_number = r;
        cout<<endl;
    }
    int roll_number;

    void display(){
        cout<<"age is: "<<age<<endl;
        cout<<"roll_number is: "<<roll_number<<endl;
        cout<<endl;
    }
    int getAge(){
        return age;
    }
};  