#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int odd = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0)
                    odd++;

                if (odd == k)
                    count++;

                if (odd > k)
                    break;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << obj.numberOfSubarrays(nums, k);

    return 0;
}