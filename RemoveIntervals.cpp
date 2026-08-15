#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                       vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        int a = toBeRemoved[0], b = toBeRemoved[1];

        for (auto &in : intervals) {
            int l = in[0], r = in[1];

            if (r <= a || l >= b) {
                ans.push_back(in);
            } 
            else {
                if (l < a)
                    ans.push_back({l, a});

                if (r > b)
                    ans.push_back({b, r});
            }
        }

        return ans;
    }
};