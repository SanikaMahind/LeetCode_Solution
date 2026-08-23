#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, -1000000000, -1000000000};

        for (int num : nums) {
            vector<int> old = dp;

            for (int r = 0; r < 3; r++) {
                if (old[r] != -1000000000) {
                    int newSum = old[r] + num;
                    int newRemainder = newSum % 3;

                    dp[newRemainder] = max(dp[newRemainder], newSum);
                }
            }
        }

        return dp[0];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 6, 5, 1, 8};

    int result = obj.maxSumDivThree(nums);

    cout << "Maximum sum divisible by 3 = " << result << endl;

    return 0;
}