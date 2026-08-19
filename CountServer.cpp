#include <bits/stdc++.h>
using namespace std;

int countServers(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> row(m, 0), col(n, 0);

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                row[i]++;
                col[j]++;
            }
        }
    }

    int ans = 0;

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0},
        {1, 1}
    };

    cout << countServers(grid);

    return 0;
}