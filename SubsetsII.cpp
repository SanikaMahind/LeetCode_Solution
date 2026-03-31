#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index, vector<int>& current) {
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            
            if (i > index && nums[i] == nums[i - 1]) continue;

            current.push_back(nums[i]);
            backtrack(nums, i + 1, current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        backtrack(nums, 0, current);
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = obj.subsetsWithDup(nums);

    cout << "Subsets are:\n";
    for (auto &subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}