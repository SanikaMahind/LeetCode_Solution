#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool match(string query, string pattern) {
        int j = 0;

        for (char c : query) {
            if (j < pattern.size() && c == pattern[j]) {
                j++;
            } else if (isupper(c)) {
                return false;
            }
        }

        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;

        for (string &q : queries) {
            result.push_back(match(q, pattern));
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<string> queries = {
        "FooBar",
        "FooBarTest",
        "FootBall",
        "FrameBuffer",
        "ForceFeedBack"
    };

    string pattern = "FB";

    vector<bool> ans = obj.camelMatch(queries, pattern);

    for (bool x : ans) {
        cout << (x ? "true" : "false") << " ";
    }

    return 0;
}