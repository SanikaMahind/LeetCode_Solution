#include <bits/stdc++.h>
using namespace std;

class CustomFunction {
public:
    int f(int x, int y) {
        return x + y;  
    }
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        vector<vector<int>> ans;

        for (int x = 1; x <= 1000; x++) {
            for (int y = 1; y <= 1000; y++) {
                int val = cf.f(x, y);

                if (val == z)
                    ans.push_back({x, y});

                if (val > z)
                    break;
            }
        }

        return ans;
    }
};

int main() {
    CustomFunction cf;
    Solution s;

    int z = 5;

    vector<vector<int>> ans = s.findSolution(cf, z);

    for (auto p : ans)
        cout << "[" << p[0] << "," << p[1] << "] ";

    return 0;
}