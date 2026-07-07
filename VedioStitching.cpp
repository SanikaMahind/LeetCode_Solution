#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        int n = clips.size();
        int i = 0, count = 0;
        int currentEnd = 0, farthest = 0;

        while (currentEnd < time) {
            while (i < n && clips[i][0] <= currentEnd) {
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            if (farthest == currentEnd)
                return -1;

            count++;
            currentEnd = farthest;
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> clips = {
        {0,2},{4,6},{8,10},{1,9},{1,5},{5,9}
    };
    int time = 10;

    cout << obj.videoStitching(clips, time) << endl;

    return 0;
}