#include <iostream>
#include <vector>
using namespace std;

// RECURSIVE //

/*int knapsack(int n, int W, vector<int>& price, vector<int>& wts) {

    // Base Case
    if(n == 0 || W == 0) {
        return 0;
    }

    // Current item cannot be included
    if(wts[n - 1] > W) {
        return knapsack(n - 1, W, price, wts);
    }

    // Include current item
    int include = price[n - 1] +
                  knapsack(n - 1, W - wts[n - 1], price, wts);

    // Exclude current item
    int exclude = knapsack(n - 1, W, price, wts);

    return max(include, exclude);
}

int main() {

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> price(n);
    vector<int> wts(n);

    cout << "Enter profits/values: ";
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) {
        cin >> wts[i];
    }

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum Profit: "
         << knapsack(n, W, price, wts) << endl;

    return 0;
}
    */

// DP solution
int knapsack(vector<int>& price, vector<int>& wts, int W) {

    int n = price.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= W; j++) {

            if(wts[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {

                int include = price[i - 1]
                            + dp[i - 1][j - wts[i - 1]];

                int exclude = dp[i - 1][j];

                dp[i][j] = max(include, exclude);
            }
        }
    }

    return dp[n][W];
}

int main() {

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> price(n);
    vector<int> wts(n);

    cout << "Enter values/profits: ";
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) {
        cin >> wts[i];
    }

    int W;
    cout << "Enter capacity: ";
    cin >> W;

    cout << "Maximum Profit: "
         << knapsack(price, wts, W) << endl;

    return 0;
}