#include <string>
#include <algorithm>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string ans = "";
        
        while (columnNumber > 0) {
       
            columnNumber--;
            
            
            char current_char = 'A' + (columnNumber % 26);
            ans += current_char;
            
            
            columnNumber /= 26;
        }
        
 
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
