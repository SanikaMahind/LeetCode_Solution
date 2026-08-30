#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        
        vector<int> freq(26, 0);

     
        for (char c : letters) {
            freq[c - 'a']++;
        }

        return backtrack(words, score, freq, 0);
    }

private:
    int backtrack(vector<string>& words, vector<int>& score,
                  vector<int>& freq, int index) {
        
        if (index == words.size()) {
            return 0;
        }

       
        int notTake = backtrack(words, score, freq, index + 1);

   
        vector<int> need(26, 0);
        int wordScore = 0;

        for (char c : words[index]) {
            need[c - 'a']++;
            wordScore += score[c - 'a'];
        }

   
        bool canTake = true;

        for (int i = 0; i < 26; i++) {
            if (need[i] > freq[i]) {
                canTake = false;
                break;
            }
        }

        int take = 0;

        if (canTake) {
           
            for (int i = 0; i < 26; i++) {
                freq[i] -= need[i];
            }

            take = wordScore +
                   backtrack(words, score, freq, index + 1);

           
            for (int i = 0; i < 26; i++) {
                freq[i] += need[i];
            }
        }

        return max(take, notTake);
    }
};

int main() {
    Solution solution;

    vector<string> words = {"dog", "cat", "dad", "good"};

    vector<char> letters = {
        'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'
    };

    vector<int> score = {
        1, 0, 9, 5, 0, 0, 3, 0, 0, 0,
        0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    };

    cout << "Maximum Score = "
         << solution.maxScoreWords(words, letters, score)
         << endl;

    return 0;
}