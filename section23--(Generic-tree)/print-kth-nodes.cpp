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
    cout<<"enter data: ";
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        int n;
        cout<<"Enter the no of children of "<<f->data<<": ";
        cin>>n;

        for(int i=1;i<=n;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<f->data<<": ";
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void printAtLevel(TreeNode<int>* root, int k){
    if(root==NULL) return;

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    for(int i=0;i<root->children.size();i++){
        printAtLevel(root->children[i], k-1);
    }
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    printAtLevel(root, 2);
    cout << endl;
    return 0;
}