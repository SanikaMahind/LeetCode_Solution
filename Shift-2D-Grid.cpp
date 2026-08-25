#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n));

        int total = m * n;

        k = k % total;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

          
                int oldPos = i * n + j;

       
                int newPos = (oldPos + k) % total;

        
                int newRow = newPos / n;
                int newCol = newPos % n;

                result[newRow][newCol] = grid[i][j];
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 1;

    vector<vector<int>> ans = s.shiftGrid(grid, k);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}