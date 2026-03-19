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

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* insertAtithPos(Node *head, int i, int data){
    if(i<0) return head;

    if(i==0){
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }
    Node *copyhead = head;
    int count = 1;
    while(count<=i-1 && head!=NULL){
        head = head->next;
        count++;
    }
    if(head){
        Node *n = new Node(data);
        n->next = head->next;
        head->next = n;
        return copyhead;
    }
    return copyhead;
}

// Node* deleteNode(Node* head, int i){
//    if(i<0){
//       return head;
//    }
//    if(i==0 && head){
//     return head->next;
//    }

//    Node* curr = head;
//    int count = 1;
//    while(count<=i-1 && curr!=NULL){
//     curr = curr->next;
//     count++;
//    }
//    if(curr && curr->next){
//     curr->next = curr->next->next;
//     return head;
//    }
//    return head;
// }

Node* deleteithNode(Node* head, int i){  // without leak
   if(i<0){
      return head;
   }
   if(i==0 && head){
    Node* newHead = head->next;
    head->next = NULL;
    delete head;
    return newHead;
   }

   Node* curr = head;
   int count = 1;
   while(count<=i-1 && curr!=NULL){
    curr = curr->next;
    count++;
   }
   if(curr && curr->next){
     Node *temp = curr->next;
     curr->next = curr->next->next;
     temp->next=NULL;
     delete temp;
     return head;
   }
   return head;
}

Node* takeInput(){
    int data;
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;

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
    Node *head = takeInput();
    // int i, data;
    // cin>>i>>data;
    // head = insertAtithPos(head, i, data);
    int i;
    cin>>i;
    head = deleteNode(head, i);
    print(head);
    return 0;
}