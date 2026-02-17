#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargest(vector<int>& nums) {
    if(nums.size() < 2) return -1;

    int largest = INT_MIN;
    int second = INT_MIN;

    for(int num : nums) {
        if(num > largest) {
            second = largest;
            largest = num;
        }
        else if(num > second && num != largest) {
            second = num;
        }
    }

    if(second == INT_MIN)
        return -1;

    return second;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = secondLargest(nums);

    if(result == -1)
        cout << "Second largest element does not exist." << endl;
    else
        cout << "Second largest element is: " << result << endl;

    return 0;
}
