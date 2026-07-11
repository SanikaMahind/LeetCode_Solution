#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= min(k, i); j++) {
            mx = max(mx, arr[i - j]);
            dp[i] = max(dp[i], dp[i - j] + mx * j);
        }
    }

    return dp[n];
}

int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "Maximum Sum: " << maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}