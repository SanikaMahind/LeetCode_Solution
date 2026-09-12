#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
       
        std::vector<int> dp = {0};
        int max_len = 0;

        for (const std::string& s : arr) {
            int mask = 0;
            bool isValid = true;

            
            for (char c : s) {
                int bit = 1 << (c - 'a');
                if (mask & bit) { 
                    isValid =false;
                    break;
                }
                mask |= bit;
            }

            if (!isValid) continue;

            
            int n = dp.size();
            for (int i = 0; i < n; ++i) {
                if ((dp[i] & mask) == 0) {
                    int new_mask = dp[i] | mask;
                    dp.push_back(new_mask);
                    
               
                    max_len = std::max(max_len, __builtin_popcount(new_mask));
                }
            }
        }

        return max_len;
    }
};