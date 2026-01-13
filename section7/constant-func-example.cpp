#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    Student(int m) {
        marks = m;
    }

    // CONST member function
    int getMarks() const {
        return marks;
    }

    // Normal (non-const) function
    void setMarks(int m) {
        marks = m;
    }
};

int main() {
    Student s(90);

    cout << s.getMarks() << endl;  // allowed

    s.setMarks(95);               // allowed
    cout << s.getMarks() << endl;

    return 0;
}
