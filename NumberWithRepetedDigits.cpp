class Solution {
public:
    int A(int m, int n) {
        int res = 1;
        for (int i = 0; i < n; i++)
            res *= (m - i);
        return res;
    }

    int numDupDigitsAtMostN(int n) {
        vector<int> digits;
        int x = n + 1;

        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());

        int m = digits.size();
        int res = 0;

        
        for (int i = 1; i < m; i++)
            res += 9 * A(9, i - 1);

       
        unordered_set<int> seen;
        for (int i = 0; i < m; i++) {
            for (int d = (i == 0 ? 1 : 0); d < digits[i]; d++) {
                if (seen.count(d)) continue;
                res += A(9 - i, m - i - 1);
            }
            if (seen.count(digits[i])) break;
            seen.insert(digits[i]);
            if (i == m - 1) res++;
        }

        return n - res;
    }
};