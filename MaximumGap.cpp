#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        // Sort the array
        sort(nums.begin(), nums.end());

        int maxGap = 0;

       
        for (int i = 1; i < n; i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }

        return maxGap;
    }
};

int main() {
    Solution obj;

    vector<int> nums;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        nums.push_back(value);
    }

    int result = obj.maximumGap(nums);

    cout << "Maximum Gap: " << result << endl;

    return 0;
}