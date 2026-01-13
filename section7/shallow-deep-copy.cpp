// Shallow Copy
// A shallow copy copies only the memory address (reference) of an object’s data, not the actual data.

// Deep Copy
// A deep copy creates a new memory location and copies the actual data into it.

#include<iostream>
#include<cstring>
using namespace std;

class Student{
    int age;
    char *name;
    public:
        Student(int age, char *name){
            this->age = age;
            // shallow copy - copy only address of 0th index
            // this->name = name; 


            // deep copy - copy the entire copy
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);

            // strlen(name) → counts characters in "sarvesh"
            // +1 → space for '\0' (null character)
            // new char[...] → allocates fresh memory
            // strcpy() → copies content into new memory
            
        }
        void display(){
            cout<<"name: "<<name<<endl;
            cout<<"age: "<<age<<endl;
        }
};

int main(){
    char name[] = "sarvesh";
    Student s1(20, name);
    s1.display();
    name[3] = 'e';
    Student s2(21, name);
    s2.display();

    s1.display();
    return 0;

}