#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> result;

        if (s.length() < 10) return result;

        for (int i = 0; i <= s.length() - 10; i++) {
            string sub = s.substr(i, 10);
            mp[sub]++;

            if (mp[sub] == 2) {
                result.push_back(sub);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter DNA string: ";
    cin >> s;

    vector<string> ans = obj.findRepeatedDnaSequences(s);

    cout << "Repeated DNA sequences are:\n";
    for (string seq : ans) {
        cout << seq << endl;
    }

    return 0;
}