#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;

        for (string s : strings) {
            string key = "";

            for (int i = 1; i < s.size(); i++) {
                int diff = (s[i] - s[i - 1] + 26) % 26;
                key += to_string(diff) + ",";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto &p : mp) {
            result.push_back(p.second);
        }

        return result;
    }
};

int main() {
    vector<string> strings = {
        "abc", "bcd", "acef", "xyz",
        "az", "ba", "a", "z"
    };

    Solution obj;
    vector<vector<string>> result = obj.groupStrings(strings);

    cout << "Grouped Shifted Strings:\n";

    for (auto &group : result) {
        cout << "[ ";
        for (auto &str : group) {
            cout << str << " ";
        }
        cout << "]\n";
    }

    return 0;
}