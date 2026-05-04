#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (wordSet.find(endWord) == wordSet.end())
            return result;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel, visited;
        currentLevel.insert(beginWord);
        visited.insert(beginWord);
        bool found = false;

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;

            for (const string& word : currentLevel)
                wordSet.erase(word); 

            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        temp[i] = c;

                        if (wordSet.count(temp)) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                        temp[i] = original;
                    }
                }
            }
            currentLevel = nextLevel;
        }

        if (!found) return result;

        
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void dfs(const string& word, const string& beginWord,
             unordered_map<string, vector<string>>& parents,
             vector<string>& path, vector<vector<string>>& result) {

        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }

        for (const string& parent : parents[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;

    string beginWord1 = "hit", endWord1 = "cog";
    vector<string> wordList1 = {"hot","dot","dog","lot","log","cog"};
    auto res1 = sol.findLadders(beginWord1, endWord1, wordList1);
    cout << "Test 1 Output:" << endl;
    for (auto& path : res1) {
        for (auto& w : path) cout << w << " ";
        cout << endl;
    }

    string beginWord2 = "hit", endWord2 = "cog";
    vector<string> wordList2 = {"hot","dot","dog","lot","log"};
    auto res2 = sol.findLadders(beginWord2, endWord2, wordList2);
    cout << "\nTest 2 Output:" << endl;
    if (res2.empty()) cout << "[]" << endl;

    return 0;
}