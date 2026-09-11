#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m, ans;

    void dfs(vector<int>& h, int cnt) {
        if (cnt >= ans) return;

        int mn = *min_element(h.begin(), h.end());

        if (mn == n) {
            ans = cnt;
            return;
        }

        int pos = find(h.begin(), h.end(), mn) - h.begin();
        int width = 0;

        while (pos + width < m && h[pos + width] == mn)
            width++;

        for (int s = min(width, n - mn); s >= 1; s--) {
            for (int i = pos; i < pos + s; i++)
                h[i] += s;

            dfs(h, cnt + 1);

            for (int i = pos; i < pos + s; i++)
                h[i] -= s;
        }
    }

public:
    int tilingRectangle(int n, int m) {
        this->n = min(n, m);
        this->m = max(n, m);
        ans = n * m;

        vector<int> h(m, 0);
        dfs(h, 0);

        return ans;
    }
};

int main() {
    Solution s;

    int n, m;
    cin >> n >> m;

    cout << s.tilingRectangle(n, m);

    return 0;
}