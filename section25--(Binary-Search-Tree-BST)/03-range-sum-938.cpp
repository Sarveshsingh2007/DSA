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

// Inorder Traversal
template<typename T>
void inorder(BTNode<T>* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Range Sum in BST (Optimized)
template<typename T>
int rangeSumBST(BTNode<T>* root, int low, int high) {
    if(root == NULL) return 0;
    if(root->data >= low && root->data <= high){
        return root->data
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
    if(root->data > high){
        return rangeSumBST(root->left, low, high);
    }
    return rangeSumBST(root->right, low, high);
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

    int low, high;
    cout << "\nEnter range (low high): ";
    cin >> low >> high;

    cout << "Range Sum: " << rangeSumBST(root, low, high);

    return 0;
}