#include<iostream>
#include <string>
using namespace std;

class Student {
    public:
        int age;
        int roll_no;
        string name;

    private:
        int id;
    
    public:
        void display(){
            cout<<"age is: "<<age<<endl;
            cout<<"roll_no is: "<<roll_no<<endl;
            cout<<"name is: "<<name<<endl;
            cout<<"id is: "<<id<<endl;
        }

        int getid(){
            return id;
        }
        void setid(int idstd){
            id = idstd;
        }

};
