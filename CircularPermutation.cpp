#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;

        for (int i = 0; i < (1 << n); i++) {
            int gray = i ^ (i >> 1);
            ans.push_back(gray ^ start);
        }

        return ans;
    }
};

int main() {
    Solution s;

    int n = 2, start = 3;
    vector<int> ans = s.circularPermutation(n, start);

    for (int x : ans)
        cout << x << " ";

    return 0;
}