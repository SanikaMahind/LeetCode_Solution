#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());

    if (!dict.count(endWord)) return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        auto front = q.front(); q.pop();
        string word = front.first;
        int steps = front.second;

        if (word == endWord) return steps;

        for (int i = 0; i < word.length(); i++) {
            string temp = word;

            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;

                if (dict.count(temp)) {
                    q.push({temp, steps + 1});
                    dict.erase(temp); 
                }
            }
        }
    }

    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int result = ladderLength(beginWord, endWord, wordList);

    cout << "Shortest Transformation Length: " << result << endl;

    return 0;
}