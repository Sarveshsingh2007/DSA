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

void print(Node * head){  // function for printing
    /*
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        */
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<" NULL";
};

int main(){
    // static object
    Node n1(20);
    Node *head = &n1;
    Node n2(30);
    Node n3(40);
    Node n4(50);
    Node n5(60);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);


    // Dynamically creating object
    // Node *n3 = 30;
    // Node *n4 = 40;
    // n3->next = n4;

    return 0;
}
