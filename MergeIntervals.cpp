#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        
        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= result.back()[1]) {
                
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } 
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = obj.merge(intervals);

    for(auto &i : ans){
        cout << "[" << i[0] << "," << i[1] << "] ";
    }

    return 0;
}