#include <iostream>
#include <vector>
using namespace std;

int m, n, original, newColor;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c) {
    visited[r][c] = true;
    bool border = false;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
            border = true;
        } else if (grid[nr][nc] != original) {
            border = true;
        } else if (!visited[nr][nc]) {
            dfs(nr, nc);
        }
    }

    if (border)
        grid[r][c] = newColor;
}

int main() {
    grid = {
        {1, 1},
        {1, 2}
    };

    int row = 0, col = 0;
    newColor = 3;

    m = grid.size();
    n = grid[0].size();
    original = grid[row][col];

    visited.assign(m, vector<bool>(n, false));

    dfs(row, col);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}