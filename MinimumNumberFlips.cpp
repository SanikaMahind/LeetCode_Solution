#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int start = 0;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j])
                    start |= (1 << (i * n + j));
            }
        }

        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push({start, 0});
        visited.insert(start);

        int dir[5][2] = {
            {0, 0},
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int state = cur.first;
            int steps = cur.second;

            if (state == 0)
                return steps;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    int next = state;

                    for (auto &d : dir) {
                        int x = i + d[0];
                        int y = j + d[1];

                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            next ^= (1 << (x * n + y));
                        }
                    }

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {0, 0},
        {0, 1}
    };

    cout << "Minimum Flips = " << obj.minFlips(mat) << endl;

    return 0;
}