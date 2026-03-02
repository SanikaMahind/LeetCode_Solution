#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int prev1 = 0;  // dp[i-1]
    int prev2 = 0;  // dp[i-2]

    for (int money : nums) {
        int temp = max(prev1, prev2 + money);
        prev2 = prev1;
        prev1 = temp;
    }

    return prev1;
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << "Maximum money robbed: " << rob(nums);
    return 0;
}