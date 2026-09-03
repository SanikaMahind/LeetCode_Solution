#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m, 0);
        vector<int> col(n, 0);

   
        for (auto index : indices) {
            row[index[0]]++;
            col[index[1]]++;
        }

        int count = 0;

      
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((row[i] + col[j]) % 2 == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    int m = 2;
    int n = 3;

    vector<vector<int>> indices = {
        {0, 1},
        {1, 1}
    };

    cout << s.oddCells(m, n, indices);

    return 0;
}