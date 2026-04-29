#include<iostream>
#include<queue>
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
};

// Take input level-wise
BTNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;

    if(rootData == -1) return NULL;

    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

        int leftChildData, rightChildData;

        cout << "Enter left child of " << f->data << ": ";
        cin >> leftChildData;

        if(leftChildData != -1){
            BTNode<int>* leftChild = new BTNode<int>(leftChildData);
            f->left = leftChild;
            q.push(leftChild);
        }

        cout << "Enter right child of " << f->data << ": ";
        cin >> rightChildData;

        if(rightChildData != -1){
            BTNode<int>* rightChild = new BTNode<int>(rightChildData);
            f->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

// Print tree (recursive)
void printTree(BTNode<int>* root){
    if(root == NULL) return;

    cout << root->data << ": ";
    if(root->left != NULL) cout << "L: " << root->left->data << " ";
    if(root->right != NULL) cout << "R: " << root->right->data << " ";
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

// Level Order Traversal (single line)
void levelOrderTraversal(BTNode<int>* root){
    if(root == NULL) return;

    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

        cout << f->data << " ";

        if(f->left != NULL) q.push(f->left);
        if(f->right != NULL) q.push(f->right);
    }
}

// Level Order Traversal (line-wise)
void levelOrderLineWise(BTNode<int>* root){
    if(root == NULL) return;

    queue<BTNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

        if(f == NULL){
            cout << endl;
            if(!q.empty()) q.push(NULL);
        } else {
            cout << f->data << " ";

            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
    }
}

int main(){
    BTNode<int>* root = takeInputLevelWise();

    cout << "\nTree (Detailed):\n";
    printTree(root);

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\n\nLevel Order (Line Wise):\n";
    levelOrderLineWise(root);

    return 0;
}