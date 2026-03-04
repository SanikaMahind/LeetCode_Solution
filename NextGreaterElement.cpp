#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;  

        for(int i = 0; i < 2 * n; i++) {
            int current = nums[i % n];

            while(!st.empty() && nums[st.top()] < current) {
                result[st.top()] = current;
                st.pop();
            }

            if(i < n) 
                st.push(i);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,2,1};

    vector<int> ans = obj.nextGreaterElements(nums);

    for(int x : ans)
        cout << x << " ";

    return 0;
}