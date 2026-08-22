#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int bx, by, sx, sy, tx, ty;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') bx = i, by = j;
                if (grid[i][j] == 'S') sx = i, sy = j;
                if (grid[i][j] == 'T') tx = i, ty = j;
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

     
        deque<array<int, 5>> q;
        set<tuple<int,int,int,int>> vis;

        q.push_front({0, bx, by, sx, sy});
        vis.insert({bx, by, sx, sy});

        while (!q.empty()) {
            auto [pushes, br, bc, pr, pc] = q.front();
            q.pop_front();

            if (br == tx && bc == ty)
                return pushes;

            for (int d = 0; d < 4; d++) {
                int nbr = br + dr[d];
                int nbc = bc + dc[d];

                if (nbr < 0 || nbr >= n || nbc < 0 || nbc >= m ||
                    grid[nbr][nbc] == '#')
                    continue;

      
                int npr = br - dr[d];
                int npc = bc - dc[d];

                if (npr < 0 || npr >= n || npc < 0 || npc >= m ||
                    grid[npr][npc] == '#')
                    continue;

            
                queue<pair<int,int>> bfs;
                set<pair<int,int>> seen;

                bfs.push({pr, pc});
                seen.insert({pr, pc});

                bool canReach = false;

                while (!bfs.empty()) {
                    auto [r, c] = bfs.front();
                    bfs.pop();

                    if (r == npr && c == npc) {
                        canReach = true;
                        break;
                    }

                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k], nc = c + dc[k];

                        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                            continue;

                        if (grid[nr][nc] == '#' ||
                            (nr == br && nc == bc))
                            continue;

                        if (!seen.count({nr, nc})) {
                            seen.insert({nr, nc});
                            bfs.push({nr, nc});
                        }
                    }
                }

                if (canReach) {
                    auto state = make_tuple(br, bc, npr, npc);

                    if (!vis.count(state)) {
                        vis.insert(state);
                        q.push_front({pushes, br, bc, npr, npc});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<vector<char>> grid = {
        {'#','#','#','#','#','#'},
        {'#','T','#','#','#','#'},
        {'#','.','.','B','.','#'},
        {'#','.','#','#','.','#'},
        {'#','.','.','S','.','#'},
        {'#','#','#','#','#','#'}
    };

    cout << "Minimum pushes = "
         << obj.minPushBox(grid) << endl;

    return 0;
}