#include<iostream>
#include<cstring>
using namespace std;

class Student{
    int age;
    
    public:
        char *name;

        Student(Student const &s){
            this->age = age;
            // this->name = name; // shallow copy inbuilt
            this->name = new char[strlen(s.name) + 1]; // deep copy
            strcpy(this->name, s.name);

        }

        Student(int age, char *name){
            this->age = age;
            // this->name = name; // shallow copy

            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        void display(){
            cout<<"name"<<name<<endl;
            cout<<"age"<<age<<endl;
        }
};
int main(){
    char name[] = "sarvesh";
    Student s1(20, name);
    s1.display();

    Student s2(s1);
    s2.name[3] = 'e';
    s1.display();
    s2.display();

}