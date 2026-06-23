#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) % 2;
    }
};

int main() {
    Solution obj;

    int n, k;
    cin >> n >> k;

    cout << obj.kthGrammar(n, k);

    return 0;
}