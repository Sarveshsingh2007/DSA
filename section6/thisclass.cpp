#include<iostream>
using namespace std;
class User{
    int id;
    int age;
public:
    User(int id, int age){
        cout<<"This address: "<<this<<endl;
        cout<<"Constructor called"<<endl;
        this->id = id;
        this->age = age;
    }
    void display(){
        cout<<"address of id is: "<< &id<<endl;
        cout<<"address of age is: "<< &age<<endl;
        cout<<"id is: "<<id<<endl;
        cout<<"age is: "<<age<<endl;
    }
};