#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions,
                              string region1, string region2) {
        
        unordered_map<string, string> parent;

     
        for (auto &r : regions) {
            string p = r[0];

            for (int i = 1; i < r.size(); i++) {
                parent[r[i]] = p;
            }
        }

  
        unordered_set<string> ancestors;

        string x = region1;
        while (true) {
            ancestors.insert(x);

            if (parent.find(x) == parent.end())
                break;

            x = parent[x];
        }

     
        string y = region2;

        while (ancestors.find(y) == ancestors.end()) {
            y = parent[y];
        }

        return y;
    }
};