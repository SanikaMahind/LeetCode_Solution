#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};

   
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }

    sort(nums.begin(), nums.end());

    cout << "Sorted Squares: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}