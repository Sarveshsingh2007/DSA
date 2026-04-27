#include<iostream>
#include<vector>
#include<queue>
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
    cout<<"Enter Root Data: ";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();
        int n;
        cout<<"Enter total no of childrens of "<<f->data<<": ";
        cin>>n;
        for(int i=0;i<n;i++){
            int childData;
            cout<<"Enter "<<i+1<<"th child: ";
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void deleteTree(TreeNode<int>* root){
    if(root== NULL) return;
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout<<endl;
    delete(root);
    cout<<"Tree Deleted";
    return 0;
}