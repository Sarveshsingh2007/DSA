#include<iostream>
using namespace std;

template<typename T>
class BTNode {
public:
    T data;
    BTNode* left;
    BTNode* right;

    BTNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Pair {
public:
    BTNode<int>* head;
    BTNode<int>* tail;
};

BTNode<int>* insertBST(BTNode<int>* root, int data) {

    if(root == NULL) {
        return new BTNode<int>(data);
    }

    if(data < root->data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }

    return root;
}

void printTree(BTNode<int>* root) {

    if(root == NULL) {
        return;
    }

    cout << root->data << ": ";

    if(root->left != NULL) {
        cout << "L" << root->left->data << " ";
    }

    if(root->right != NULL) {
        cout << "R" << root->right->data;
    }

    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

Pair convertToLL(BTNode<int>* root) {

    if(root == NULL) {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    if(root->left == NULL && root->right == NULL) {
        Pair ans;
        ans.head = root;
        ans.tail = root;
        return ans;
    }

    if(root->left != NULL && root->right == NULL) {

        Pair leftLL = convertToLL(root->left);

        leftLL.tail->right = root;

        Pair ans;
        ans.head = leftLL.head;
        ans.tail = root;

        return ans;
    }

    if(root->left == NULL && root->right != NULL) {

        Pair rightLL = convertToLL(root->right);

        root->right = rightLL.head;

        Pair ans;
        ans.head = root;
        ans.tail = rightLL.tail;

        return ans;
    }

    Pair leftLL = convertToLL(root->left);
    Pair rightLL = convertToLL(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    Pair ans;
    ans.head = leftLL.head;
    ans.tail = rightLL.tail;

    return ans;
}

int main() {

    BTNode<int>* root = NULL;

    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 1);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 5);
    root = insertBST(root, 7);

    cout << "BST:\n";
    printTree(root);

    Pair p = convertToLL(root);
    BTNode<int>* temp = p.head;

    while(temp != NULL) {
        temp->left = NULL;
        temp = temp->right;
    }
    cout << "\nLinked List:\n";

    temp = p.head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->right;
    }

    cout << "NULL";

    return 0;
}