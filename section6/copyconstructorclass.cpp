#include<iostream>
using namespace std;
 
class Employee{
    int id;
public:    
    int age;
    Employee(int id, int age){
        cout<<"parameterized constructor called"<<endl;
        this->id = id;
        this->age = age;
    }
    void display(){
        cout<<"id is: "<<id<<endl;
        cout<<"age is: "<<age<<endl;
    }

    ~Employee(){
        cout<<"Destructor called"<<endl;
    }
};