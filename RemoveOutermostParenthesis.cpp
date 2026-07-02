#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0)
                    ans += c;
                balance++;
            } else {
                balance--;
                if (balance > 0)
                    ans += c;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    string s = "(()())(())(()(()))";
    cout << obj.removeOuterParentheses(s) << endl;
    return 0;
}