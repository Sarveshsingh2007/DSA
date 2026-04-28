#include<iostream>
using namespace std;
template<typename T>

class BTNode {
public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;
    BTNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode() {
        delete left;
        delete right;
    }
};

BTNode<int>* takeInputRecursive(){
    int rootData;
    cout<<"Enter Data: ";
    cin>>rootData;
    if (rootData == -1) {
        return NULL;
    }
    BTNode<int>* root = new BTNode<int>(rootData);

    cout << "Enter left of " << rootData << endl;
    root->left = takeInputRecursive();

    cout << "Enter right of " << rootData << endl;
    root->right = takeInputRecursive();

    return root;

}

void printrecursive(BTNode<int>* root) {
    if (root == NULL) return;
    cout << root->data << ": ";
    if (root->left != NULL) {
        cout << "L: " << root->left->data << " ";
    }
    if (root->right != NULL) {
        cout << "R: " << root->right->data;
    }
    cout << endl;
    printrecursive(root->left);
    printrecursive(root->right);
}

int main(){
    BTNode<int>* root = takeInputRecursive();
    printrecursive(root);
    return 0;

}