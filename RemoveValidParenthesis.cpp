#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0;

      
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                balance++;
            }
            else if (s[i] == ')') {
                if (balance == 0) {
                    s[i] = '#';
                }
                else {
                    balance--;
                }
            }
        }


        for (int i = s.length() - 1; i >= 0 && balance > 0; i--) {
            if (s[i] == '(') {
                s[i] = '#';
                balance--;
            }
        }

        
        string ans = "";

        for (char c : s) {
            if (c != '#') {
                ans += c;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    string str = "lee(t(c)o)de)";

    cout << s.minRemoveToMakeValid(str);

    return 0;
}