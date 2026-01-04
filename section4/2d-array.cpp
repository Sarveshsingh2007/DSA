#include <iostream>
using namespace std;

int main() {
    int a[20][20];
    int m, n;

    cout << "Enter total rows: ";
    cin >> m;
    cout << "Enter total columns: ";
    cin >> n;

    // Input 
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Output
    cout << "\nMatrix is:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
