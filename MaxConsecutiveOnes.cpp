#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int findMaxConsecutiveOnes(vector<int>& nums){
     int ans =0,cnt =0;

     for(int x:nums){
        if(x==1){
            cnt++;
            ans=max(ans,cnt);

        }
        else{
            cnt=0;
        }
     }
     return ans;

    }
};
int main(){
    Solution s;
    int n;

    cout<<"Enter number of elements:";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enetr elements(only 0s and 1s):";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result=s.findMaxConsecutiveOnes(nums);

    cout<< "Maximum number of consecutives 1's:"<<result<< endl;
    return 0;
}


    
