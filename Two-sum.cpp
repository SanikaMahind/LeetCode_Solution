#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();

    for(int i=0;i<n;i++)
    {
    for(int j=i+1;j<n;j++)
    {
        if(nums[i]+nums[j]==target)
        {
            ans.push_back(i); //ans[0]=i;
            ans.push_back(j); //ans[1]=j;
            return ans;
    }
  }

 }
    return ans;
}   
};
int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> result = obj.twoSum(nums, target);

    if(result.size() == 2) {
        cout << "Indexes: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}