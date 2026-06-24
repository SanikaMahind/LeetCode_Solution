#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        int sum = 0;
        int mn = nums[0];

        for (int x : nums) {
            sum += x;
            mn = min(mn, x);
        }

        if (k % 2 == 1)
            sum -= 2 * mn;

        return sum;
    }
};

int main() {
    vector<int> nums = {4, 2, 3};
    int k = 1;

    Solution obj;
    cout << obj.largestSumAfterKNegations(nums, k);

    return 0;
}