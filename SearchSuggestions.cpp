#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());

    vector<vector<string>> ans;
    string prefix;

    for (char c : searchWord) {
        prefix += c;
        vector<string> temp;

        for (string p : products) {
            if (p.compare(0, prefix.size(), prefix) == 0) {
                temp.push_back(p);
                if (temp.size() == 3)
                    break;
            }
        }

        ans.push_back(temp);
    }

    return ans;
}

int main() {
    vector<string> products = {
        "mobile", "mouse", "moneypot", "monitor", "mousepad"
    };

    string searchWord = "mouse";

    vector<vector<string>> ans = suggestedProducts(products, searchWord);

    for (auto v : ans) {
        for (string s : v)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}