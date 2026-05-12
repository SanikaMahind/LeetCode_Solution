#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;

        return solve(s, dict, memo);
    }

    vector<string> solve(string s,
                         unordered_set<string>& dict,
                         unordered_map<string, vector<string>>& memo) {

        if (memo.count(s))
            return memo[s];

        vector<string> result;

        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);

            if (dict.count(word)) {
                string remaining = s.substr(i);

                vector<string> subList = solve(remaining, dict, memo);

                for (string sub : subList) {
                    if (sub.empty())
                        result.push_back(word);
                    else
                        result.push_back(word + " " + sub);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};

int main() {
    Solution obj;

    string s = "catsanddog";

    vector<string> wordDict = {
        "cat", "cats", "and", "sand", "dog"
    };

    vector<string> ans = obj.wordBreak(s, wordDict);

    cout << "Possible Sentences:\n";

    for (string str : ans) {
        cout << str << endl;
    }

    return 0;
}