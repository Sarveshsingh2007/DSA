#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> ans;

    int m = matrix.size();
    int n = matrix[0].size();

    int sr = 0, er = m-1, sc = 0, ec = n-1;
    int count = 0;

    while (sr<=er && sc<=ec){

        // top row
        for (int i=sc;i<=ec;i++){
            ans.push_back(matrix[sr][i]);
            count++;
        }
        sr++;
        if(count == m*n) return ans;

        // right column
        for (int i=sr;i<=er;i++){
            ans.push_back(matrix[i][ec]);
            count++;
        }
        ec--;
        if(count == m*n) return ans;

        // bottom row
        for (int i=ec;i>=sc;i--){
            ans.push_back(matrix[er][i]);
            count++;
        }
        er--;
        if(count == m*n) return ans;

        // left column
        for (int i=er;i>=sr;i--){
            ans.push_back(matrix[i][sc]);
            count++;
        }
        sc++;
        if(count == m*n) return ans;
    }
    return ans;
}

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}