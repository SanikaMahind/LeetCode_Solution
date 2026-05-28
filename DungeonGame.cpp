
#include <vector>
#include <algorithm>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
       
     std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        
        
        dp[rows - 1][cols - 1] = std::max(1, 1 - dungeon[rows - 1][cols - 1]);
        
      
        for (int i = rows - 2; i >= 0; --i) {
            dp[i][cols - 1] = std::max(1, dp[i + 1][cols - 1] - dungeon[i][cols - 1]);
        }
        
  
        for (int j = cols - 2; j >= 0; --j) {
            dp[rows - 1][j] = std::max(1, dp[rows - 1][j + 1] - dungeon[rows - 1][j]);
        }
        
       
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = cols - 2; j >= 0; --j) {
               
                int min_health_next = std::min(dp[i + 1][j], dp[i][j + 1]);
                
               
                dp[i][j] = std::max(1, min_health_next - dungeon[i][j]);
            }
        }
        
        
        return dp[0][0];
    }
};
