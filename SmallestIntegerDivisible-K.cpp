#include <iostream>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int rem = 0;

        for (int len = 1; len <= k; len++) {
            rem = (rem * 10 + 1) % k;

            if (rem == 0)
                return len;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    int k;
    cout << "Enter k: ";
    cin >> k;

    int ans = obj.smallestRepunitDivByK(k);

    cout << "Smallest Length = " << ans << endl;

    return 0;
}