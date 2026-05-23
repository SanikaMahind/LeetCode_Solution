#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long prev = (long)lower - 1;
        long curr;

        for (int i = 0; i <= nums.size(); i++) {
            if (i == nums.size())
                curr = (long)upper + 1;
            else
                curr = nums[i];

            if (curr - prev >= 2) {
                result.push_back(formatRange(prev + 1, curr - 1));
            }

            prev = curr;
        }

        return result;
    }

    string formatRange(long lower, long upper) {
        if (lower == upper)
            return to_string(lower);
        return to_string(lower) + "->" + to_string(upper);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    vector<string> ans = obj.findMissingRanges(nums, lower, upper);

    cout << "Missing Ranges are:" << endl;

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}