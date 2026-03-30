#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = 1 << n; 

        for (int i = 0; i < size; i++) {
            result.push_back(i ^ (i >> 1));
        }

        return result;
    }
};

int main() {
    Solution obj;
    int n = 2;

    vector<int> res = obj.grayCode(n);

    cout << "Gray Code sequence: ";
    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}