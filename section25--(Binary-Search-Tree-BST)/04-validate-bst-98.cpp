#include<iostream>
#include<climits>
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

// Validate BST
bool isValidBST(BTNode<int>* root, long long minVal, long long maxVal) {
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal) return false;

    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
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

    if(isValidBST(root, LLONG_MIN, LLONG_MAX)) {
        cout << "\nValid BST.";
    } else {
        cout << "\nNot a BST.";
    }

    return 0;
}