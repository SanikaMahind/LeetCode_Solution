#include<iostream>
#include<vector>
using namespace std;

vector<int> ShuffleTheArray(vector<int>& nums, int n)
{

vector<int>ans(2*n);

int ans_i=0;
for(int i=0;i<n;i++)
{
    ans[ans_i]=nums[i];
    ans[ans_i+1]=nums[i+n];
    ans_i+=2;

}
   return ans;
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> nums(2 * n);
    cout << "Enter " << 2 * n << " elements:\n";
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = ShuffleTheArray(nums, n);

    cout << "Shuffled The array: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
};
