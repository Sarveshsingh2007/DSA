#include<iostream>
using namespace std;
class Student{
    public:
        int age;
        const int rollNumber;
        int &x; // age reference variable

        Student(int age, int r): rollNumber(r), age(age), x(this->age) {
            // roll_number = r; wrong once const is used value cannot be changed for that we have to use intialisation list

        }
        void display(){
            cout<<rollNumber<<" "<<age<<endl;
        }
};
int main(){
        Student s1(100, 10);
        s1.display();
        // s1.roll_number();
    return 0;
}