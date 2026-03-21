#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev1 = 2; 
    int prev2 = 1; 
    int curr;

    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Number of ways: " << climbStairs(n) << endl;

    return 0;
}