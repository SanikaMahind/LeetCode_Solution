class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;

        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == destination[0] && y == destination[1])
                return true;

            for (auto &[dx, dy] : dirs) {
                int nx = x;
                int ny = y;

           
                while (nx + dx >= 0 && nx + dx < m &&
                       ny + dy >= 0 && ny + dy < n &&
                       maze[nx + dx][ny + dy] == 0) {
                    nx += dx;
                    ny += dy;
                }

                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};