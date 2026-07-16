#include <iostream>
#include <unordered_map>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    unordered_map<char, int> mp;

    for (char ch : jewels) {
        mp[ch] = 1;
    }

    int count = 0;

    for (char ch : stones) {
        if (mp.find(ch) != mp.end()) {
            count++;
        }
    }

    return count;
}

int main() {
    string jewels, stones;

    cout << "Enter jewels: ";
    cin >> jewels;

    cout << "Enter stones: ";
    cin >> stones;

    cout << "Number of jewels in stones = "
         << numJewelsInStones(jewels, stones);

    return 0;
}