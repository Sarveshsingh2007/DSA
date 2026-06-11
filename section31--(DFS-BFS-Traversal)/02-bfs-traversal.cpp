#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printBFS(vector<vector<int>> v, int sv){
    int n = v.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int cv = q.front();
        q.pop();
        cout << cv << " ";
        for(int i = 0; i < n; i++){
            if(v[cv][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    cout << "Enter edges (source destination):\n";
    for(int i = 0; i < e; i++){
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    cout << "\nBFS Traversal: ";
    printBFS(matrix, 0);
    return 0;
}

/*
Sample Run:

Enter number of vertices: 4
Enter number of edges: 3
Enter edges (source destination):
0 1
0 2
1 3

Graph:
      0
     / \
    1   2
   /
  3

BFS Traversal: 0 1 2 3

Explanation:
Start from 0

Queue = [0]

Visit 0
Add 1, 2

Queue = [1, 2]

Visit 1
Add 3

Queue = [2, 3]

Visit 2

Queue = [3]

Visit 3

Queue = []

Final Output:
0 1 2 3
*/