#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<int> dp = grid[0];

    for (int i = 1; i < n; i++) {
        int min1 = INT_MAX, min2 = INT_MAX, idx = -1;

        for (int j = 0; j < n; j++) {
            if (dp[j] < min1) {
                min2 = min1;
                min1 = dp[j];
                idx = j;
            } else if (dp[j] < min2) {
                min2 = dp[j];
            }
        }

        vector<int> newDp(n);

        for (int j = 0; j < n; j++) {
            if (j == idx)
                newDp[j] = grid[i][j] + min2;
            else
                newDp[j] = grid[i][j] + min1;
        }

        dp = newDp;
    }

    int ans = INT_MAX;
    for (int x : dp)
        ans = min(ans, x);

    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Minimum Falling Path Sum II = "
         << minFallingPathSum(grid) << endl;

    return 0;
}