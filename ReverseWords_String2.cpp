#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<char>& s, int left, int right) {
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};

    int n = s.size();

    reverse(s, 0, n - 1);

    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }

    for (char c : s) {
        cout << c;
    }

    return 0;
}