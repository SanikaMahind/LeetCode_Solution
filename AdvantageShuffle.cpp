class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(n);
        int left = 0, right = n - 1;

        for (int num : nums1) {
            if (num > v[left].first) {
                ans[v[left].second] = num;
                left++;
            } else {
                ans[v[right].second] = num;
                right--;
            }
        }

        return ans;
    }
};