#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        priority_queue<pair<int,char>> pq;

        for (int i = 0; i < 26; i++)
            if (freq[i])
                pq.push({freq[i], 'a' + i});

        string ans;

        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();

            ans += c1;
            ans += c2;

            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});
        }

        if (!pq.empty()) {
            auto [f, c] = pq.top();

            if (f > 1)
                return "";

            ans += c;
        }

        return ans;
    }
};

int main() {
    Solution s;

    string str = "aab";
    cout << s.reorganizeString(str);

    return 0;
}