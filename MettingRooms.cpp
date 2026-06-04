#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {0, 30},
        {35, 40},
        {50, 60}
    };

    if (obj.canAttendMeetings(intervals))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}