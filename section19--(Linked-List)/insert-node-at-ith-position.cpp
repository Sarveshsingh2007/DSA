#include<iostream>
using namespace std;

class Node {
   public:
     int data;
     Node *next;

     Node(int data){
       this->data = data;
       next = NULL;
     }
};

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* insertAtithPos(Node *head, int i, int data){
      if(i<0){
        return head;
      }
      if(i==0){
        Node* n = new Node(data);
        n->next = head;
        head = n;
        return head;
      }
      Node * copyHead = head;
      int count = 1;
      while(count<=i-1 && head!=NULL){
        head = head->next;
        count++;
      }
      if(head){
        /*Node *n = new Node(data);
        n->next = head->next;
        head->next = n;*/
        Node *n = new Node(data);
        Node *temp = head->next;
        head->next = n;
        n->next = temp;
        return copyHead;
      }
      return copyHead;
}

Node* takeInput(){
   int data;
   cin>>data;
   Node *head = NULL; 
   Node *tail = NULL;  
   while(data != -1){
    Node *n = new Node(data);
    if(head == NULL){
        head = n;
        tail = n;
    }else {
        tail -> next = n;
        tail = n;
    }

    cin>>data;
   }
   return head;

}

int main(){. // main function 
   Node *head = takeInput(); 
   int i,data;
   cin>>i>>data;
   head = insertAtithPos(head,i,data);
   print(head);
   return 0;
}