#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]) !=
               (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]);
    }
};

int main() {
    Solution obj;

    vector<vector<int>> points = {{1, 1}, {2, 3}, {3, 2}};

    if (obj.isBoomerang(points))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}