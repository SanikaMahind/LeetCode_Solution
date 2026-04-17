#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("words.txt");  
    string word;

    map<string, int> freq;

   
    while (file >> word) {
        freq[word]++;
    }

    
    vector<pair<string, int>> vec(freq.begin(), freq.end());

    
    sort(vec.begin(), vec.end(), [](pair<string, int> &a, pair<string, int> &b) {
        if (a.second == b.second)
            return a.first < b.first; 
        return a.second > b.second;
    });

   
    for (auto &p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}