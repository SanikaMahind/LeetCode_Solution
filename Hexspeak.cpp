#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toHexspeak(string num) {
        long long n = stoll(num);
        string ans;

        while (n > 0) {
            int d = n % 16;
            if (d == 0) ans += 'O';
            else if (d == 1) ans += 'I';
            else if (d >= 2 && d <= 9) ans += char('0' + d);
            else if (d == 10) ans += 'A';
            else if (d == 11) ans += 'B';
            else if (d == 12) ans += 'C';
            else if (d == 13) ans += 'D';
            else if (d == 14) ans += 'E';
            else ans += 'F';

            n /= 16;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.toHexspeak("257") << endl;
    return 0;
}