#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int right = -1;

        for (auto &x : intervals) {
            if (x[1] > right) {
                count++;
                right = x[1];
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    vector<vector<int>> intervals = {
        {1, 4},
        {3, 6},
        {2, 8}
    };

    cout << s.removeCoveredIntervals(intervals);

    return 0;
}