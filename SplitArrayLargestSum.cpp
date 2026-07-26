#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int parts = 1;
        long long sum = 0;

        for (int x : nums) {
            if (sum + x > maxSum) {
                parts++;
                sum = x;
            } else {
                sum += x;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << s.splitArray(nums, k);

    return 0;
}