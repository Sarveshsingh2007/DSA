#include<iostream>
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

BTNode<int>* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int postS, int postE){
    if(inS > inE) return NULL;
    int rootData = postorder[postE];   
    int rootIndex = -1;
    for(int i = inS; i <= inE; i++){
        if(inorder[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int leftSize = rootIndex - inS;

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPostS = postS;
    int leftPostE = postS + leftSize - 1;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPostS = postS + leftSize;
    int rightPostE = postE - 1;

    BTNode<int>* root = new BTNode<int>(rootData);
    root->left = buildTreeHelper(inorder, postorder, leftInS, leftInE, leftPostS, leftPostE);
    root->right = buildTreeHelper(inorder, postorder, rightInS, rightInE, rightPostS, rightPostE);
    return root;
}

BTNode<int>* buildTree(vector<int>& postorder, vector<int>& inorder){
    int n = inorder.size();
    return buildTreeHelper(inorder, postorder, 0, n-1, 0, n-1);
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

int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    vector<int> postorder(n), inorder(n);

    cout<<"Enter postorder: ";
    for(int i=0;i<n;i++) cin>>postorder[i];

    cout<<"Enter inorder: ";
    for(int i=0;i<n;i++) cin>>inorder[i];

    BTNode<int>* root = buildTree(postorder, inorder);

    cout<<"Tree:"<<endl;
    printTree(root);

    return 0;
}