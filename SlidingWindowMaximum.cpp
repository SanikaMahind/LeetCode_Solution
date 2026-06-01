#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

           
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

           
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution obj;
    vector<int> result = obj.maxSlidingWindow(nums, k);

    cout << "Output: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}