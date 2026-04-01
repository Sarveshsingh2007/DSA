#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* createCLL(int n){
    if(n <= 0) return NULL;

    int data;
    cin >> data;
    Node* head = new Node(data);
    Node* tail = head;

    for(int i = 1; i < n; i++){
        cin >> data;
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
    tail->next = head;
    return head;
}

void print(Node* head){
    if(head == NULL){
        cout << "Empty\n";
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != head);
    cout << "(head)\n";
}

int length(Node* head){
    if(head == NULL) return 0;
    int len = 0;
    Node* temp = head;
    do{
        len++;
        temp = temp->next;
    }while(temp != head);
    return len;
}

Node* insertAtHead(Node* head, int data){
    Node* n = new Node(data);
    if(head == NULL){
        n->next = n;
        return n;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    return n;
}

Node* insertAtTail(Node* head, int data){
    Node* n = new Node(data);
    if(head == NULL){
        n->next = n;
        return n;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    return head;
}

Node* insertAtPosition(Node* head, int pos, int data){
    if(pos == 0) return insertAtHead(head, data);

    int len = length(head);
    if(pos > len) return head;

    Node* temp = head;
    for(int i = 0; i < pos-1; i++){
        temp = temp->next;
    }

    Node* n = new Node(data);
    n->next = temp->next;
    temp->next = n;

    return head;
}

Node* deleteNode(Node* head, int key){
    if(head == NULL) return NULL;

    Node* temp = head;
    Node* prev = NULL;

    if(head->data == key){
        Node* last = head;
        while(last->next != head){
            last = last->next;
        }
        if(last == head){
            delete head;
            return NULL;
        }
        last->next = head->next;
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    do{
        prev = temp;
        temp = temp->next;
        if(temp->data == key){
            prev->next = temp->next;
            delete temp;
            return head;
        }
    }while(temp != head);

    return head;
}

bool search(Node* head, int key){
    if(head == NULL) return false;
    Node* temp = head;
    do{
        if(temp->data == key) return true;
        temp = temp->next;
    }while(temp != head);
    return false;
}

int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    Node* head = createCLL(n);

    print(head);

    int data;
    cout << "Insert at head: ";
    cin >> data;
    head = insertAtHead(head, data);
    print(head);

    cout << "Insert at tail: ";
    cin >> data;
    head = insertAtTail(head, data);
    print(head);

    int pos;
    cout << "Insert at position (pos data): ";
    cin >> pos >> data;
    head = insertAtPosition(head, pos, data);
    print(head);

    cout << "Length: " << length(head) << endl;

    int key;
    cout << "Search element: ";
    cin >> key;
    cout << (search(head, key) ? "Found\n" : "Not Found\n");

    cout << "Delete element: ";
    cin >> key;
    head = deleteNode(head, key);
    print(head);

    return 0;
}