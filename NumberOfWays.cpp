#include <bits/stdc++.h>
using namespace std;

int numWays(int steps, int arrLen) {
    const int MOD = 1e9 + 7;
    int n = min(steps, arrLen);

    vector<long long> dp(n, 0), next(n, 0);
    dp[0] = 1;

    for (int s = 0; s < steps; s++) {
        fill(next.begin(), next.end(), 0);

        for (int i = 0; i < n; i++) {
            next[i] = dp[i];

            if (i > 0)
                next[i] = (next[i] + dp[i - 1]) % MOD;

            if (i + 1 < n)
                next[i] = (next[i] + dp[i + 1]) % MOD;
        }

        dp = next;
    }

    return dp[0];
}

int main() {
    int steps, arrLen;
    cin >> steps >> arrLen;

    cout << numWays(steps, arrLen);

    return 0;
}