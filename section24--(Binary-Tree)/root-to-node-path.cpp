#include<iostream>
#include<queue>
#include<vector>
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

BTNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;

    if(rootData == -1) return NULL;

    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

        int leftChild, rightChild;

        cout<<"Enter left child of "<<f->data<<": ";
        cin>>leftChild;

        if(leftChild != -1){
            BTNode<int>* child = new BTNode<int>(leftChild);
            f->left = child;
            q.push(child);
        }

        cout<<"Enter right child of "<<f->data<<": ";
        cin>>rightChild;

        if(rightChild != -1){
            BTNode<int>* child = new BTNode<int>(rightChild);
            f->right = child;
            q.push(child);
        }
    }
    return root;
}

void printTree(BTNode<int>* root){
    if(root==NULL) return;

    cout<<root->data<<": ";
    if(root->left) cout<<"L: "<<root->left->data<<" ";
    if(root->right) cout<<"R: "<<root->right->data<<" ";
    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

bool getPath(BTNode<int>* root, int val, vector<int>& path){
    if(root == NULL) return false;

    path.push_back(root->data);

    if(root->data == val) return true;

    if(getPath(root->left, val, path) || getPath(root->right, val, path)){
        return true;
    }

    path.pop_back(); // backtrack
    return false;
}

int main(){
    BTNode<int>* root = takeInputLevelWise();

    cout<<"\nTree:\n";
    printTree(root);

    int target;
    cout<<"\nEnter value to find path: ";
    cin>>target;

    vector<int> path;

    if(getPath(root, target, path)){
        cout<<"Path: ";
        for(int x : path){
            cout<<x<<" ";
        }
    } else {
        cout<<"Value not found";
    }

    return 0;
}