#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;

       
        while (i < s.length() && s[i] == ' ')
            i++;

        
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

       
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            
            if (sign * result >= INT_MAX)
                return INT_MAX;
            if (sign * result <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * result;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int result = obj.myAtoi(s);
    cout << "Converted integer: " << result << endl;

    return 0;
}
