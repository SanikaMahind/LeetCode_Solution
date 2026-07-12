#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();

        int maxMoves = max(stones[n - 1] - stones[1] + 1 - (n - 1),
                           stones[n - 2] - stones[0] + 1 - (n - 1));
 
        int minMoves = n;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n)
                j++;

            int already = j - i + 1;

            if (already == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                minMoves = min(minMoves, 2);
            else
                minMoves = min(minMoves, n - already);
        }

        return {minMoves, maxMoves};
    }
};

int main() {
    Solution obj;

    vector<int> stones = {7, 4, 9};

    vector<int> ans = obj.numMovesStonesII(stones);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}