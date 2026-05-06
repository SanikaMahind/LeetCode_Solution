#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string> &path, vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, path, result);
                path.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }
};

int main() {
    string s = "aab";

    Solution obj;
    vector<vector<string>> ans = obj.partition(s);

    for (auto &vec : ans) {
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}