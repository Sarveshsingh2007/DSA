#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T>

class TreeNode{
    public:
    T  data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data = data;
    }
};

//Take input
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter data: ";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        cout<<"Enter no of children of "<<f->data<<endl;
        int n;
        cin>>n;

        for(int i=;i<=n;i++){
            int childData;
            cout<<"Enter "<< i << "th child of "<<f->data<<endl;
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();
        cout<<f->data<<": ";
        for(int i=0;i<f->children.size();i++){
            cout<<f->children[i]->data<<", ";
        }
        cout<<endl;
        for(int i=0;i<f->children.size();i++){
            q.push(f->children[i]);
        }
    }
    return root;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
    return 0;
}