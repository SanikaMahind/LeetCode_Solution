#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());  
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> input = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = sol.groupAnagrams(input);

    cout << "Grouped Anagrams:\n";
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
