#include<iostream>
#include<vector>
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

// Build BST from sorted array
template<typename T>
BTNode<T>* buildBST(vector<T>& arr, int s, int e) {
    if(s > e) return NULL;

    int mid = (s + e) / 2;

    BTNode<T>* root = new BTNode<T>(arr[mid]);

    root->left = buildBST(arr, s, mid - 1);
    root->right = buildBST(arr, mid + 1, e);

    return root;
}

// Inorder Traversal (should print sorted)
template<typename T>
void inorder(BTNode<T>* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cout << "Enter size of sorted array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted values: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    BTNode<int>* root = buildBST(arr, 0, n - 1);

    cout << "\nInorder Traversal of BST: ";
    inorder(root);

    return 0;
}