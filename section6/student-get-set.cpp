#include <iostream>
#include "studentclass.cpp"
using namespace std;

int main() {
    Student s4;

    s4.age = 24;
    s4.roll_no = 12;
    s4.name = "Sarvesh";

    s4.setid(124);                 // set ID
    cout << "ID is: " << s4.getid();  // get & print ID

    return 0;
}
