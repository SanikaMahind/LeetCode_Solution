#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diameter = 0;

    int dfs(int node, int parent, vector<vector<int>>& graph) {
        int longest = 0;
        int secondLongest = 0;

        for (int child : graph[node]) {
            if (child == parent)
                continue;

            int depth = dfs(child, node, graph) + 1;

            if (depth > longest) {
                secondLongest = longest;
                longest = depth;
            }
            else if (depth > secondLongest) {
                secondLongest = depth;
            }
        }

        diameter = max(diameter, longest + secondLongest);

        return longest;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> graph(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, graph);

        return diameter;
    }
};