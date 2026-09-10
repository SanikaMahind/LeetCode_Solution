#include <iostream>
#include <vector>
using namespace std;

vector<int> transformArray(vector<int>& arr) {
    bool changed = true;

    while (changed) {
        changed = false;
        vector<int> temp = arr;

        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                temp[i]++;
                changed = true;
            }
            else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                temp[i]--;
                changed = true;
            }
        }

        arr = temp;
    }

    return arr;
}

int main() {
    vector<int> arr = {6, 2, 3, 4};

    vector<int> result = transformArray(arr);

    for (int x : result)
        cout << x << " ";

    return 0;
}