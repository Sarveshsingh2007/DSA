#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

// Print Doubly Linked List
void print(Node *head){
    Node *temp = head;
    cout << "Doubly Linked List: ";
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert at ith position
Node* insertAtithPos(Node *head, int i, int data){
    if(i < 0){
        cout << "Invalid position!" << endl;
        return head;
    }

    // Insert at head
    if(i == 0){
        Node* n = new Node(data);
        n->next = head;
        if(head != NULL){
            head->prev = n;
        }
        return n;
    }

    Node *temp = head;
    int count = 0;

    while(count < i-1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp != NULL){
        Node *n = new Node(data);

        n->next = temp->next;
        n->prev = temp;

        if(temp->next != NULL){
            temp->next->prev = n;
        }

        temp->next = n;
    } else {
        cout << "Position out of range!" << endl;
    }

    return head;
}

// Take input (-1 to stop)
Node* takeInput(){
    int data;
    cout << "Enter elements of DLL (-1 to stop): ";
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1){
        Node *n = new Node(data);

        if(head == NULL){
            head = n;
            tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }

        cin >> data;
    }

    return head;
}

int main(){
    Node *head = takeInput();

    int i, data;
    cout << "Enter position (i) and data to insert: ";
    cin >> i >> data;

    head = insertAtithPos(head, i, data);

    print(head);

    return 0;
}