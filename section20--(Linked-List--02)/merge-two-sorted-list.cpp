#include <iostream>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to insert node at end
void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Merge Two Sorted Lists (your logic)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main() {
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;

    int n1, n2, x;

    // Input first list
    cout << "Enter number of elements in list1: ";
    cin >> n1;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n1; i++) {
        cin >> x;
        insertNode(list1, x);
    }

    // Input second list
    cout << "Enter number of elements in list2: ";
    cin >> n2;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n2; i++) {
        cin >> x;
        insertNode(list2, x);
    }

    cout << "\nList 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge
    ListNode* merged = mergeTwoLists(list1, list2);

    cout << "\nMerged List: ";
    printList(merged);

    return 0;
}