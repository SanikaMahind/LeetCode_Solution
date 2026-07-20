#include <iostream>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mp;

    for (char ch : magazine) {
        mp[ch]++;
    }

    for (char ch : ransomNote) {
        if (mp[ch] == 0)
            return false;
        mp[ch]--;
    }

    return true;
}

int main() {
    string ransomNote = "aa";
    string magazine = "aab";

    if (canConstruct(ransomNote, magazine))
        cout << "true";
    else
        cout << "false";

    return 0;
}