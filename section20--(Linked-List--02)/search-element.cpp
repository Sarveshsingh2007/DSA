#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
/*
void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}


int length(Node *head){
    if(head == NULL) return 0;
    return 1 + length(head->next);
}
    */  

// SEARCH ELEMENT IN LINKED LIST
bool isPresent(Node *head, int data){
    Node *curr = head;
    while(curr!=NULL){
        if(curr->data == data){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// SEARCH ELEMENT IN LINKED LIST USING RECURSION
bool findElement(Node *head, int data){
    if(head == NULL) return false;
    if(head->data == data) return true;
    return isPresent(head->next, data);
}

Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data!=-1){
        Node *n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}

int main(){
    Node *head = takeInput();
    // print(head);
    // cout<<endl;
    // cout<<"length of linked list is: "<<length(head)<<endl;

    int data;
    cin>>data;
    if(isPresent(head, data)){  // without recursion
        cout<<"Found";
    }else{
        cout<<"Not Found";
    }
    cout<<endl;

    if(findElement(head, data)){
        cout<<"Found";
    }else{
        cout<<"Not Found";
    }


    return 0;
}