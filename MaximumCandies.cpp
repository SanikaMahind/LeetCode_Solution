#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> haveBox(n, false);
        vector<bool> haveKey(n, false);
        vector<bool> visited(n, false);

        queue<int> q;

        for (int box : initialBoxes) {
            haveBox[box] = true;
            q.push(box);
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            if (visited[box])
                continue;

        
            if (status[box] == 0 && !haveKey[box]) {
                continue;
            }

            visited[box] = true;
            totalCandies += candies[box];
            for (int key : keys[box]) {
                haveKey[key] = true;

                if (haveBox[key] && !visited[key]) {
                    q.push(key);
                }
           }
            for (int newBox : containedBoxes[box]) {
                haveBox[newBox] = true;

                if (status[newBox] == 1 || haveKey[newBox]) {
                    q.push(newBox);
                }
            }
        }

        return totalCandies;
    }
};

int main() {
    Solution obj;

    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};

    vector<vector<int>> keys = {
        {},
        {3},
        {},
        {}
    };

    vector<vector<int>> containedBoxes = {
        {1, 2},
        {},
        {3},
        {}
    };

    vector<int> initialBoxes = {0};

    cout << obj.maxCandies(status, candies, keys,
                           containedBoxes, initialBoxes);

    return 0;
}