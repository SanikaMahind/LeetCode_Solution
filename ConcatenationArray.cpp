#include<iostream>
#include<vector>
using namespace std;

vector<int> getConcatenation(vector<int>& nums)
  
{

    int Sz=nums.size();
    vector<int>ans(Sz*2);

  for(int i=0;i<Sz;i++)
 {
    ans[i]=nums[i];
    ans[i+Sz]=nums[i];
 }

return ans;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = getConcatenation(nums);

    cout << "Concatenated array: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

