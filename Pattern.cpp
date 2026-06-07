#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third)
                return true;

            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 1, 4, 2};

    if (obj.find132pattern(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}