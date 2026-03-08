#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

int main(){
    // static object
    Node n1(20);
    Node n2(30);
    n1.next = &n2;
    cout<<n1.data<<" "<<n2.data<<endl;
    Node *head = &n1;
    cout<<"Head Element: ";
    cout<<head->data<<endl;

    return 0;
}