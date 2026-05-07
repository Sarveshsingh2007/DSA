#include<iostream>
using namespace std;

template<typename T>
class BTNode{
public:
    T data;
    BTNode* left;
    BTNode* right;

    BTNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BTNode(){
        delete left;
        delete right;
    }
};

class BST{
    BTNode<int>* root;

    //  Recursive Insert Helper
    BTNode<int>* insert(BTNode<int>* node, int data){
        if(node == NULL){
            return new BTNode<int>(data);
        }

        if(data < node->data){
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }

        return node;
    }

    // Print Tree
    void printTree(BTNode<int>* root){
        if(root == NULL){
            return;
        }

        cout << root->data << ": ";

        if(root->left != NULL){
            cout << "L" << root->left->data << " ";
        }

        if(root->right != NULL){
            cout << "R" << root->right->data;
        }

        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }

    // Search Helper
    bool hasData(BTNode<int>* node, int data){
        if(node == NULL){
            return false;
        }

        if(node->data == data){
            return true;
        }

        if(data < node->data){
            return hasData(node->left, data);
        } else {
            return hasData(node->right, data);
        }
    }

public:
    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }

    // Public Insert
    void insert(int data){
        root = insert(root, data);
    }

    // Delete (empty for now)
    void deleteData(int data){

    }

    bool hasData(int data){
        return hasData(root, data);
    }

    void print(){
        printTree(root);
    }
};

int main(){

    BST b;

    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(3);
    b.insert(7);

    cout << "BST Structure:\n";
    b.print();

    cout << "\nSearching 7: ";
    if(b.hasData(7)){
        cout << "Found ✅";
    } else {
        cout << "Not Found ❌";
    }

    cout << "\nSearching 15: ";
    if(b.hasData(15)){
        cout << "Found ✅";
    } else {
        cout << "Not Found ❌";
    }

    return 0;
}