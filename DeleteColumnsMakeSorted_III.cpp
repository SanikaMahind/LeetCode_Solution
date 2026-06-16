class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<int> dp(n, 1);
        int longest = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                bool valid = true;

                for (int k = 0; k < m; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            longest = max(longest, dp[i]);
        }

        return n - longest;
    }
};