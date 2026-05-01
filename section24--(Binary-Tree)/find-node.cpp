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

bool searchNode(BTNode<int>* root, int key){
    if(root==NULL) return false;
    if(root->data == key) return true;
    return (searchNode(root->left, key) || searchNode(root->right, key));
}
int main(){
    BTNode<int>* root = takeInputLevelWise();
    cout<<"Tree: "<<endl;
    printTree(root);
    int key;
    cout<<"Enter value to find in tree: ";
    cin>>key;
    cout<<"Searching for "<<key<<": "<<endl;
    if(searchNode(root, key)){
        cout<<key<<" found in tree"<<endl;
    }else{
        cout<<key<<" not found in tree";
    }
    return 0;
}