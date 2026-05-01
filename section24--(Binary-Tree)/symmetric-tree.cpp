#include<iostream>
#include<queue>
#include<algorithm>
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

// Input
BTNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter Data: ";
    cin>>rootData;

    if (rootData == -1) return NULL;

    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

        int leftChildData, rightChildData;

        cout<<"Enter left child of "<<f->data<<": ";
        cin>>leftChildData;

        if(leftChildData!=-1){
            BTNode<int>* leftChild = new BTNode<int>(leftChildData);
            f->left = leftChild;
            q.push(leftChild);
        }

        cout<<"Enter right child of "<<f->data<<": ";
        cin>>rightChildData;

        if(rightChildData!=-1){
            BTNode<int>* rightChild = new BTNode<int>(rightChildData);
            f->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

// Print Tree
void printTree(BTNode<int>* root){
    if(root==NULL) return;

    cout<<root->data<<": ";
    if(root->left) cout<<"L: "<<root->left->data<<" ";
    if(root->right) cout<<"R: "<<root->right->data<<" ";
    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

// Mirror Check
bool isMirror(BTNode<int>* left, BTNode<int>* right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;
    if(left->data != right->data) return false;
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Symmetric Check
bool isSymmetric(BTNode<int>* root){
    if(root == NULL) return true;
    return isMirror(root->left, root->right);
}

int main(){
    BTNode<int>* root = takeInputLevelWise();
    cout << "\nTree:\n";
    printTree(root);
    if(isSymmetric(root)){
        cout << "Tree is Symmetric\n";
    } else {
        cout << "Tree is NOT Symmetric\n";
    }
    return 0;
}