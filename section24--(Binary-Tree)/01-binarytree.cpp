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
    BTNode<int>* root = new BTNode<int>(1);
    BTNode<int>* n1 = new BTNode<int>(2);
    BTNode<int>* n2 = new BTNode<int>(3);
    root->left = n1;
    root->right = n2;
    printrecursive(root);
    return 0;

}