#include <iostream>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        return (n % 2 == 0);
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    if (obj.divisorGame(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}