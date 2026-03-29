#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> mp;

public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;

        if (s1.length() != s2.length())
            return false;

        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end())
            return mp[key];

        int n = s1.length();

        
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b)
            return mp[key] = false;

        for (int i = 1; i < n; i++) {
           
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return mp[key] = true;

            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i)))
                return mp[key] = true;
        }

        return mp[key] = false;
    }
};

int main() {
    Solution obj;

    string s1 = "great";
    string s2 = "rgeat";

    if (obj.isScramble(s1, s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}