#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(int num) {
        num = num - 1;

        string ans = "";

        while (num > 0) {
            ans += char('0' + (num % 2));
            num = num / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution obj;

    int num;
    cin >> num;

    cout << obj.encode(num) << endl;

    return 0;
}