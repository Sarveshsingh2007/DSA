#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // move fast pointer n+1 steps
        for (int i = 0; i <= n; i++) {
            if (fast != NULL)
                fast = fast->next;
        }

        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// 🔹 Build list from user input
ListNode* buildListFromUser() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) return NULL;

    int val;
    cout << "Enter values: ";

    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    return head;
}

// 🔹 Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    ListNode* head = buildListFromUser();

    cout << "Enter n (node to remove from end): ";
    int n;
    cin >> n;

    cout << "Input:  ";
    printList(head);

    head = sol.removeNthFromEnd(head, n);

    cout << "Output: ";
    printList(head);

    return 0;
}