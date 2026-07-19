#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];

        long long total = pre[n - 1];
        unordered_map<long long, int> right, left;

        for (int i = 0; i < n - 1; i++)
            right[pre[i]]++;

        int ans = (total % 2 == 0) ? right[total / 2] : 0;

        for (int i = 0; i < n; i++) {
            long long diff = k - nums[i];
            int cur = 0;

            cur += left[(total + diff) / 2];
            cur += right[(total - diff) / 2];

            if ((total + diff) % 2 == 0)
                ans = max(ans, cur);

            if (i < n - 1) {
                right[pre[i]]--;
                left[pre[i]]++;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, -1, 2};
    int k = 3;

    cout << obj.waysToPartition(nums, k) << endl;

    return 0;
}