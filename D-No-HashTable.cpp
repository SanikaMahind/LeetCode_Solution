#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Hashtable to store present numbers
    unordered_set<int> st(nums.begin(), nums.end());

    vector<int> ans;

    // Check numbers from 1 to n
    for (int num = 1; num <= n; num++) {
        if (st.find(num) == st.end()) {
            ans.push_back(num);
        }
    }

    cout << "Disappeared numbers: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
