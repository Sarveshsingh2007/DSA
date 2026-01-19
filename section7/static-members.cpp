#include<iostream>
using namespace std;

class Student{
    public:
        int roll;
        int age;
        static int total_stu; // total no of students present
};

int Student::total_stu = 0; // initialize staic data member

int main(){

    Student s1;
    cout<<s1.roll<<" "<<s1.age<<endl;
    cout<<s1.total_stu<<endl;

    s1.total_stu = 20;

    Student s2;
    cout<<s2.total_stu<<endl;


    cout<<Student::total_stu<<endl;
    
    return 0;
}