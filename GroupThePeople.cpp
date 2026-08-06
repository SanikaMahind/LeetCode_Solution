#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];
            mp[size].push_back(i);

            if (mp[size].size() == size) {
                result.push_back(mp[size]);
                mp[size].clear();
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> groupSizes = {3,3,3,3,3,1,3};

    vector<vector<int>> ans = obj.groupThePeople(groupSizes);

    cout << "Groups are:\n";
    for (auto &group : ans) {
        cout << "[ ";
        for (int person : group) {
            cout << person << " ";
        }
        cout << "]\n";
    }

    return 0;
}