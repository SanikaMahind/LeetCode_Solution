#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> child(n);
        for (int i = 1; i < n; i++)
            child[parent[i]].push_back(i);

        function<pair<int,int>(int)> dfs = [&](int u) {
            int sum = value[u], nodes = 1;

            for (int v : child[u]) {
                auto [s, cnt] = dfs(v);
                sum += s;
                nodes += cnt;
            }

            if (sum == 0) return make_pair(0, 0);
            return make_pair(sum, nodes);
        };

        return dfs(0).second;
    }
};

int main() {
    Solution s;

    int n = 7;
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    vector<int> value = {1, -1, 0, 0, 0, 0, -1};

    cout << s.deleteTreeNodes(n, parent, value);

    return 0;
}