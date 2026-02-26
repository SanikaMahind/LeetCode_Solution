#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string current = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');  
            }
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(current);
                k = 0;
                current = "";
            }
            else if (c == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string temp = current;
                current = stringStack.top();
                stringStack.pop();

                while (repeat--) {
                    current += temp;
                }
            }
            else {
                current += c;
            }
        }

        return current;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter encoded string: ";
    cin >> s;

    cout << "Decoded string: " << sol.decodeString(s);

    return 0;
}