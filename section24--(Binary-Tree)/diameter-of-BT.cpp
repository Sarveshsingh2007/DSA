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
            BTNode<int>* leftNode = new BTNode<int>(leftChild);
            f->left = leftNode;
            q.push(leftNode);
        }

        cout<<"Enter right child of "<<f->data<<": ";
        cin>>rightChild;

        if(rightChild != -1){
            BTNode<int>* rightNode = new BTNode<int>(rightChild);
            f->right = rightNode;
            q.push(rightNode);
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

pair<int,int> heightDiameter(BTNode<int>* root){
    if(root == NULL) return {0, 0};

    auto left = heightDiameter(root->left);
    auto right = heightDiameter(root->right);

    int height = 1 + max(left.first, right.first);
    int diameter = max(left.first + right.first,
                       max(left.second, right.second));

    return {height, diameter};
}

int diameterOfBinaryTree(BTNode<int>* root){
    return heightDiameter(root).second;
}

int main(){
    BTNode<int>* root = takeInputLevelWise();

    cout<<"\nTree:\n";
    printTree(root);

    cout<<"Diameter: "<<diameterOfBinaryTree(root)<<endl;

    return 0;
}