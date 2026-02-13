#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());

        unordered_map<int, string> mp;

        for(int i = 0; i < sorted.size(); i++) {
            if(i == 0) mp[sorted[i]] = "Gold Medal";
            else if(i == 1) mp[sorted[i]] = "Silver Medal";
            else if(i == 2) mp[sorted[i]] = "Bronze Medal";
            else mp[sorted[i]] = to_string(i + 1);
        }

        vector<string> result;
        for(int s : score)
            result.push_back(mp[s]);

        return result;
    }
};

int main() {
    Solution obj;
    
    vector<int> score = {10, 3, 8, 9, 4};   
    
    vector<string> result = obj.findRelativeRanks(score);

    cout << "Relative Ranks:\n";
    for(string s : result)
        cout << s << " ";

    return 0;
}
