#include <iostream>
#include <vector>
#include <queue>
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

void printTree(TreeNode<int>* root){
    if(root == NULL) return;

    cout << root->data << ": ";
    for(int i = 0; i < root->children.size(); i++){
        cout << root->children[i]->data << " ";
    }
    cout << endl;

    for(int i = 0; i < root->children.size(); i++){
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        cout << "Enter no of children of " << f->data << ": ";
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            int childData;
            cout << "Enter " << i+1 << "th child: ";
            cin >> childData;

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

        cout << f->data << ": ";
        for(int i = 0; i < f->children.size(); i++){
            cout << f->children[i]->data << " ";
            q.push(f->children[i]);
        }
        cout << endl;
    }
}

int countNodes(TreeNode<int>* root){
    if(root == NULL) return 0;

    int ans = 1;
    for(int i = 0; i < root->children.size(); i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int>* root){
    if(root == NULL) return 0;

    int mx = 0;
    for(int i = 0; i < root->children.size(); i++){
        int childHeight = height(root->children[i]);
        mx = max(mx, childHeight);
    }
    return mx + 1;
}

void printAtLevelK(TreeNode<int>* root, int k){
    if(root == NULL) return;

    if(k == 0){
        cout << root->data << " ";
        return;
    }

    for(int i = 0; i < root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
}

int countLeafNodes(TreeNode<int>* root){
    if(root == NULL) return 0;

    if(root->children.size() == 0) return 1;

    int ans = 0;
    for(int i = 0; i < root->children.size(); i++){
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();

    printTreeLevelWise(root);

    cout << "Total nodes: " << countNodes(root) << endl;
    cout << "Height: " << height(root) << endl;

    cout << "Nodes at level 2: ";
    printAtLevelK(root, 2);
    cout << endl;

    cout << "Leaf nodes: " << countLeafNodes(root) << endl;

    return 0;
}