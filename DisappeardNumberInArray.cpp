#include <iostream>
#include <vector>
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

    vector<int> ans;

    for (int num = 1; num <= n; num++) {
        bool flag = false;

        for (int j = 0; j < n; j++) {
            if (nums[j] == num) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            ans.push_back(num);
        }
    }

    cout << "Disappeared numbers: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
