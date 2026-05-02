#include<iostream>
#include<queue>
#include <climits>
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
            BTNode<int> * leftChild = new BTNode<int>(leftChildData);
            f->left = leftChild;
            q.push(leftChild);
        }
        cout<<"Enter right child of "<<f->data<<": ";
        cin>>rightChildData;
        if(rightChildData!=-1){
            BTNode<int> * rightChild = new BTNode<int>(rightChildData);
            f->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
    
}
void printTree(BTNode<int>* root){
    if(root==NULL) return;
    cout<<root->data<<": ";
    if(root->left!=NULL) cout<<"L: "<<root->left->data<<" ";
    if(root->right!=NULL) cout<<"R: "<<root->right->data<<" ";
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int countLeafNodes(BTNode<int>* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void countLeafNodesOtherWay(BTNode<int>* root, int &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        ans++;
        return;
    }
    countLeafNodesOtherWay(root->left, ans);
    countLeafNodesOtherWay(root->right, ans);
}

int main(){
    BTNode<int>* root = takeInputLevelWise();
    cout<<"Tree: "<<endl;
    printTree(root);
    cout<<"Total Leaf Nodes: "<<countLeafNodes(root)<<endl;

    int count = 0;
    cout<<"Total Leaf Nodes other way: ";
    countLeafNodesOtherWay(root, count);
    cout<<count<<endl;
    return 0;
}