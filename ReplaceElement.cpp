#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxRight = -1;

        for (int i = arr.size() - 1; i >= 0; i--) {
            int current = arr[i];
            arr[i] = maxRight;
            if (current > maxRight) {
                maxRight = current;
            }
        }

        return arr;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {17, 18, 5, 4, 6, 1};

    vector<int> result = obj.replaceElements(arr);

    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}