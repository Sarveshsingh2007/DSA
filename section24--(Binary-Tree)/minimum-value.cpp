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

int minValue(BTNode<int>* root){
    if(root==NULL) return INT_MAX;

    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);

    return min(root->data, min(leftMin, rightMin));
}


void minValueOtherWay(BTNode<int>* root,int &ans){
    if(root==NULL){
        return;
    }
    ans = min(ans,root->data);
    minValueOtherWay(root->left,ans);
    minValueOtherWay(root->right,ans);
}

int main(){
    BTNode<int>* root = takeInputLevelWise();
    cout<<"Tree: "<<endl;
    printTree(root);
    cout<<"Minimum value: "<<minValue(root)<<endl;

    cout<<"Min value other way ";
    int mnVal = INT_MAX;
    minValueOtherWay(root,mnVal);
    cout<<mnVal<<endl;

    return 0;
}