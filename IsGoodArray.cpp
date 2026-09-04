#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;

        for (int num : nums) {
            g = gcd(g, num);

            if (g == 1)
                return true;
        }

        return false;
    }
};

int main() {
    Solution s;

    vector<int> nums = {12, 5, 7, 23};

    cout << (s.isGoodArray(nums) ? "true" : "false");

    return 0;
}