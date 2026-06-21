class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> commonFreq(26, INT_MAX);

        for (string &word : words) {
            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                commonFreq[i] = min(commonFreq[i], freq[i]);
            }
        }

        vector<string> result;

        for (int i = 0; i < 26; i++) {
            while (commonFreq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                commonFreq[i]--;
            }
        }

        return result;
    }
};