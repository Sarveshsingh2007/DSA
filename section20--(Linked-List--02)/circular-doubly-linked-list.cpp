#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node* createCDLL(int n){
    if(n <= 0) return NULL;

    int data;
    cin >> data;
    Node* head = new Node(data);
    Node* tail = head;

    for(int i = 1; i < n; i++){
        cin >> data;
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    tail->next = head;
    head->prev = tail;

    return head;
}

void print(Node* head){
    if(head == NULL){
        cout << "Empty\n";
        return;
    }

    Node* temp = head;
    do{
        cout << temp->data << " <-> ";
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
        n->prev = n;
        return n;
    }

    Node* tail = head->prev;

    n->next = head;
    n->prev = tail;

    tail->next = n;
    head->prev = n;

    return n;
}

Node* insertAtTail(Node* head, int data){
    Node* n = new Node(data);

    if(head == NULL){
        n->next = n;
        n->prev = n;
        return n;
    }

    Node* tail = head->prev;

    tail->next = n;
    n->prev = tail;

    n->next = head;
    head->prev = n;

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
    n->prev = temp;

    temp->next->prev = n;
    temp->next = n;

    return head;
}

Node* deleteNode(Node* head, int key){
    if(head == NULL) return NULL;

    Node* temp = head;

    if(head->data == key){
        if(head->next == head){
            delete head;
            return NULL;
        }

        Node* tail = head->prev;

        Node* newHead = head->next;

        tail->next = newHead;
        newHead->prev = tail;

        delete head;
        return newHead;
    }

    do{
        if(temp->data == key){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
            return head;
        }
        temp = temp->next;
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
    Node* head = createCDLL(n);

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