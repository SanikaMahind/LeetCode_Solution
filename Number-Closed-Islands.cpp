#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;

       
        if (grid[r][c] == 1)
            return;

       
        grid[r][c] = 1;

        dfs(grid, r + 1, c); 
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1); 
        dfs(grid, r, c - 1); 
    }

    int closedIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, cols - 1);
        }

        for (int j = 0; j < cols; j++) {
            dfs(grid, 0, j);
            dfs(grid, rows - 1, j);
        }

        int count = 0;

        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {

                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};

int main() {

    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    Solution obj;

    cout << "Number of closed islands: "
         << obj.closedIsland(grid) << endl;

    return 0;
}