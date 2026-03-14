#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int length(Node *head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}


Node* takingInput(){
    int data;
    cin>>data;
    Node *head = NULL;  
    Node *tail = NULL;
    
    while(data!= -1){
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
    Node *head = takingInput();
    print(head);
    cout<<"Length: "<<length(head)<<endl;
    return 0;
}