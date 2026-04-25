#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data){
            this->data = data;
        }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        int n;
        cout<<"Enter the no of children of "<<f->data<<endl;
        cin>>n;

        for(int i=1;i<=n;i++){
            int childData;
            cout<<"Enter "<<i<<" th child of "<<f->data<<": ";
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode<int>* root){
    if(root == NULL) return;

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        cout << f->data << " : ";
        for(int i=0;i<f->children.size();i++){
            cout<<f->children[i]->data<<" ";
            q.push(f->children[i]);
        }
        cout<<endl;
    }
}

int countNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    int ans = 1;
    for(int i=0;i<root->children.size();i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();

    cout<<"Total Nodes: "<<countNodes(root)<<endl;
    cout<<"Tree:"<<endl;

    printTreeLevelWise(root);

    return 0;
}