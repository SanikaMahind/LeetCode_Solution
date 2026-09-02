#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        
        int n = colsum.size();

        vector<int> top(n, 0);
        vector<int> bottom(n, 0);

        
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                top[i] = 1;
                bottom[i] = 1;

                upper--;
                lower--;
            }
        }
        if (upper < 0 || lower < 0) {
            return {};
        }

      
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1) {
                
                if (upper > 0) {
                    top[i] = 1;
                    upper--;
                }
                else if (lower > 0) {
                    bottom[i] = 1;
                    lower--;
                }
                else {
                    return {};
                }
            }
        }

      
        if (upper != 0 || lower != 0) {
            return {};
        }

        return {top, bottom};
    }
};

int main() {
    Solution obj;

    int upper = 2;
    int lower = 1;

    vector<int> colsum = {1, 1, 1};

    vector<vector<int>> ans = obj.reconstructMatrix(upper, lower, colsum);

    if (ans.empty()) {
        cout << "Not possible" << endl;
    }
    else {
        for (auto row : ans) {
            for (int x : row) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}