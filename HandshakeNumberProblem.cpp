#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int numPeople) {
        const long long MOD = 1000000007;

        vector<long long> dp(numPeople + 1, 0);

        dp[0] = 1;
        dp[2] = 1;

        for (int n = 4; n <= numPeople; n += 2) {
            for (int i = 0; i <= n - 2; i += 2) {
                dp[n] = (dp[n] + dp[i] * dp[n - 2 - i]) % MOD;
            }
        }

        return dp[numPeople];
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of people: ";
    cin >> n;

    cout << "Number of ways = " << obj.numberOfWays(n) << endl;

    return 0;
}