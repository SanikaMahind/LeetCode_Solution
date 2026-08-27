#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> adj;
unordered_map<string, int> id;
vector<string> words;
vector<string> ans;

void dfs(int pos, vector<string>& sentence) {
    if (pos == sentence.size()) {
        string s = "";

        for (int i = 0; i < sentence.size(); i++) {
            if (i > 0) s += " ";
            s += sentence[i];
        }

        ans.push_back(s);
        return;
    }

    string word = sentence[pos];

    
    dfs(pos + 1, sentence);

    
    if (id.count(word)) {
        for (string synonym : adj[id[word]]) {
            sentence[pos] = synonym;
            dfs(pos + 1, sentence);
        }
    }

 
    sentence[pos] = word;
}

vector<string> generateSentences(vector<vector<string>>& synonyms,
                                 string text) {
    
    for (auto& pair : synonyms) {
        for (string word : pair) {
            if (!id.count(word)) {
                int index = words.size();
                id[word] = index;
                words.push_back(word);
                adj.push_back({});
            }
        }
    }

   
    for (auto& pair : synonyms) {
        int u = id[pair[0]];
        int v = id[pair[1]];

        adj[u].push_back(pair[1]);
        adj[v].push_back(pair[0]);
    }

    stringstream ss(text);
    vector<string> sentence;
    string word;

    while (ss >> word) {
        sentence.push_back(word);
    }

    dfs(0, sentence);

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<vector<string>> synonyms = {
        {"happy", "joy"},
        {"sad", "sorrow"},
        {"joy", "cheerful"}
    };

    string text = "I am happy but sad";

    vector<string> result = generateSentences(synonyms, text);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}