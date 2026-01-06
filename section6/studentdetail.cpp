#include <iostream>
#include <cstring>
#include "studentclass.cpp"
using namespace std;

int main() {
    // creating objects statically
    Student s1;
    s1.age = 24;
    s1.roll_no = 12;
    s1.name= "sarvesh singh";

    // creating objects dynamically
    Student* s2 = new Student;
    s2->age = 25;
    s2->roll_no = 13;
    s2->name= "adhikari";

    cout << "Name of student 1 is: " << s1.name << endl;
    cout << "Roll no of student 1 is: " << s1.roll_no << endl;
    cout << "Age of student 1 is: " << s1.age << endl;

    cout << endl;

    cout << "Name of student 2 is: " << s2->name << endl;
    cout << "Roll no of student 2 is: " << s2->roll_no << endl;
    cout << "Age of student 2 is: " << s2->age << endl;

    delete s2; // free dynamically allocated memory

    return 0;
}
