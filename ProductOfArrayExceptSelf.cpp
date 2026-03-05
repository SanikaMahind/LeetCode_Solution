#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();
    vector<int> result(n);

    int left = 1;
    for(int i = 0; i < n; i++)
    {
        result[i] = left;
        left = left * nums[i];
    }

    int right = 1;
    for(int i = n-1; i >= 0; i--)
    {
        result[i] = result[i] * right;
        right = right * nums[i];
    }

    return result;
}

int main()
{
    vector<int> nums = {1,2,3,4};

    vector<int> ans = productExceptSelf(nums);

    for(int x : ans)
        cout << x << " ";

    return 0;
}