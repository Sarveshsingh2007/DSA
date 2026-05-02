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

BTNode<int>* buildTreeHelper(vector<int>& inorder, vector<int>& preorder,
                             int inS, int inE, int preS, int preE){

    if(inS > inE) return NULL;

    int rootData = preorder[preS];
    int rootIndex = -1;

    for(int i = inS; i <= inE; i++){
        if(inorder[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPreS = preS + 1;
    int leftPreE = leftPreS + leftInE - leftInS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    BTNode<int>* root = new BTNode<int>(rootData);

    root->left = buildTreeHelper(inorder, preorder,
                                 leftInS, leftInE, leftPreS, leftPreE);

    root->right = buildTreeHelper(inorder, preorder,
                                  rightInS, rightInE, rightPreS, rightPreE);

    return root;
}

BTNode<int>* buildTree(vector<int>& preorder, vector<int>& inorder){
    int n = inorder.size();
    return buildTreeHelper(inorder, preorder, 0, n-1, 0, n-1);
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

    vector<int> preorder(n), inorder(n);

    cout<<"Enter preorder: ";
    for(int i=0;i<n;i++) cin>>preorder[i];

    cout<<"Enter inorder: ";
    for(int i=0;i<n;i++) cin>>inorder[i];

    BTNode<int>* root = buildTree(preorder, inorder);

    cout<<"Tree:"<<endl;
    printTree(root);

    return 0;
}