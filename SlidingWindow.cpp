#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {
        
   
       while (window.find(s[right]) != window.end()) {
            window.erase(s[left]);
            left++;
        }

        window.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Longest substring length: " 
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}