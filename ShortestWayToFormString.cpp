#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int count = 0;
        int i = 0;

        while (i < target.size()) {
            int prev = i;

            for (char c : source) {
                if (i < target.size() && c == target[i]) {
                    i++;
                }
            }

            if (prev == i)
                return -1;

            count++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    string source = "abc";
    string target = "abcbc";

    cout << obj.shortestWay(source, target) << endl;

    return 0;
}