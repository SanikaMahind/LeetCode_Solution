#include <iostream>
#include <vector>
using namespace std;

class StreamChecker {
    vector<string> words;
    string s;

public:
    StreamChecker(vector<string> w) { words = w; }

    bool query(char c) {
        s += c;
        for (string w : words) {
            if (s.size() >= w.size() &&
                s.substr(s.size() - w.size()) == w)
                return true;
        }
        return false;
    }
};

int main() {
    vector<string> words = {"cd", "f", "kl"};
    StreamChecker sc(words);

    string stream = "abcdefghijkl";
    for (char c : stream)
        cout << (sc.query(c) ? "true " : "false ");

    return 0;
}