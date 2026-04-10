#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();

        if (abs(m - n) > 1) return false;

        if (m > n) return isOneEditDistance(t, s);

        bool foundDiff = false;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (s[i] != t[j]) {
                if (foundDiff) return false;

                foundDiff = true;

                if (m == n) {
                    i++; j++;
                } else {
                    j++; 
                }
            } else {
                i++; j++;
            }
        }

       
        return foundDiff || (m < n);
    }
};

int main() {
    Solution obj;

    string s = "ab";
    string t = "acb";

    if (obj.isOneEditDistance(s, t))
        cout << "True";
    else
        cout << "False";

    return 0;
}