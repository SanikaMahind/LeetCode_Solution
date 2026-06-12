class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return (double)arr[a.first] / arr[a.second] >
                   (double)arr[b.first] / arr[b.second];
        };

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            decltype(cmp)
        > pq(cmp);

        for (int j = 1; j < n; j++) {
            pq.push({0, j});
        }

        while (--k) {
            auto [i, j] = pq.top();
            pq.pop();

            if (i + 1 < j) {
                pq.push({i + 1, j});
            }
        }

        auto [i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};