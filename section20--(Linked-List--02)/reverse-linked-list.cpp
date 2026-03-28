#include <iostream>
using namespace std;

// Node class
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Insert at end
ListNode* insert(ListNode* head, int val) {
    if (head == NULL) {
        return new ListNode(val);
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new ListNode(val);
    return head;
}

// Reverse linked list
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;

    while (curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insert(head, x);
    }

    cout << "\nOriginal List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}