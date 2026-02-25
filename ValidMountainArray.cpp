#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        
       
        if (n < 3) return false;
        
        int i = 0;

        
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

       
        if (i == 0 || i == n - 1) return false;

        
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {0, 3, 2, 1};
    vector<int> arr2 = {3, 5, 5};
    vector<int> arr3 = {0, 1, 2, 3, 2, 1};

    cout << "arr1: " << (obj.validMountainArray(arr1) ? "true" : "false") << endl;
    cout << "arr2: " << (obj.validMountainArray(arr2) ? "true" : "false") << endl;
    cout << "arr3: " << (obj.validMountainArray(arr3) ? "true" : "false") << endl;

    return 0;
}