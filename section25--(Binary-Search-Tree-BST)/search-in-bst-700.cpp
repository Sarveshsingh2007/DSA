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
// Insert into BST
template<typename T>
BTNode<T>* insertBST(BTNode<T>* root, T val) {
    if(root == NULL) {
        return new BTNode<T>(val);
    }

    if(val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

// Inorder Traversal (Sorted)
template<typename T>
void inorder(BTNode<T>* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search in BST
template<typename T>
BTNode<T>* searchBST(BTNode<T>* root, T val) {
    while(root != NULL) {
        if(root->data == val) return root;

        if(val > root->data) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return NULL;
}

int main() {
    BTNode<int>* root = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    cout << "\nInorder Traversal (Sorted BST): ";
    inorder(root);

    int key;
    cout << "\nEnter value to search: ";
    cin >> key;

    BTNode<int>* result = searchBST(root, key);

    if(result != NULL) {
        cout << "Value found in BST";
    } else {
        cout << "Value not found";
    }

    return 0;
}