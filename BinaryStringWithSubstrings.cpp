#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = n; i > n / 2; i--) {
            string binary = "";

            int num = i;
            while (num > 0) {
                binary = char((num % 2) + '0') + binary;
                num /= 2;
            }

            if (s.find(binary) == string::npos)
                return false;
        }
        return true;
    }
};

int main() {
    Solution obj;

    string s;
    int n;

    cout << "Enter binary string: ";
    cin >> s;

    cout << "Enter n: ";
    cin >> n;

    if (obj.queryString(s, n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}