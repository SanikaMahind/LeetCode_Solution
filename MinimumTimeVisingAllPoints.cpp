#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;

        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);

            time += max(dx, dy);
        }

        return time;
    }
};

int main() {
    Solution s;

    vector<vector<int>> points = {
        {1, 1},
        {3, 4},
        {-1, 0}
    };

    cout << "Minimum Time = "
         << s.minTimeToVisitAllPoints(points);

    return 0;
}
