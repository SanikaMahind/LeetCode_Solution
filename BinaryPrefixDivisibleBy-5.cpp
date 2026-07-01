#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int rem = 0;

        for (int bit : nums) {
            rem = (rem * 2 + bit) % 5;
            result.push_back(rem == 0);
        }

        return result;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<bool> ans = obj.prefixesDivBy5(nums);

    for (bool x : ans) {
        cout << (x ? "true" : "false") << " ";
    }

    return 0;
}